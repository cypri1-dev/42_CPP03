/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:51:30 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/07 16:49:44 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

/*--------------------------------------------------------ORTHODOX CANONICAL FORM---------------------------------------------------------*/

ScavTrap::ScavTrap() : ClapTrap() {
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDamage = 20;
	this->_guardMode = false;
	std::cout << BOLD_ON GREEN << "Default (SCAV) constructor called!" << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string const name) : ClapTrap(name) {
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDamage = 20;
	this->_guardMode = false;
	std::cout << BOLD_ON YELLOW << "Custom (SCAV) constructor called!" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	std::cout << BOLD_ON YELLOW << "Copy (SCAV) constructor called!" << RESET << std::endl;
	*this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap other) {
	std::cout << BOLD_ON YELLOW << "Copy (SCAV) assigment called!" << RESET << std::endl;
	if (this != &other)
	{
		this->_name = other.getName();
		this->_hitPoint = other.getHitPoint();
		this->_energyPoint = other.getEnergyPoint();
		this->_attackDamage = other.getAttackDamage();
		this->_guardMode = other.getGuardMode();
	}
	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout << BOLD_ON RED << "Destructor (SCAV) called!" << RESET << std::endl;
}

/*-----------------------------------------------------GETRER - SETTER -----------------------------------------------------------------*/

bool ScavTrap::getGuardMode(void)const {
	return (this->_guardMode);
}

void ScavTrap::setGuardMode(void) {
	this->_guardMode = true;
}

/*---------------------------------------------------------OVERLOAD OP--------------------------------------------------------------------*/

std::ostream& operator<<(std::ostream& out, const ScavTrap& scav) {
	out << BOLD_ON << "My name is " << scav.getName() << RESET << std::endl
	<< BOLD_ON << "Hit point --> " << scav.getHitPoint() << RESET << std::endl
	<< BOLD_ON << "Energy point --> " << scav.getEnergyPoint() << RESET << std::endl
	<< BOLD_ON << "Attack damage --> " << scav.getAttackDamage() << RESET << std::endl
	<< BOLD_ON << "GuardMode --> " << scav.getGuardMode() << RESET << std::endl;
	return (out);
}

/*---------------------------------------------------------FUNCTIONS----------------------------------------------------------------------*/

void ScavTrap::attack(const std::string &target) {
	unsigned int oldEnergyPoint = this->getEnergyPoint();

	if (this->getEnergyPoint() == 0)
	{
		std::cout << BOLD_ON RED << "No more energy! Can't do anything!" << RESET << std::endl;
		return;
	}
	this->setEnergyPoint(oldEnergyPoint - 1);
	std::cout << "ScavTrap " << BOLD_ON BLUE << this->getName() << RESET << " slays " << BOLD_ON YELLOW << target << RESET << ", causing " << BOLD_ON RED << this->getAttackDamage() << RESET << " points of damage!" << std::endl;
}

void ScavTrap::guardGate(void) {
	if (!this->getGuardMode())
	{
		this->setGuardMode();
		std::cout << "ScavTrap " << BOLD_ON BLUE << this->getName() << RESET << " turned in " << BOLD_ON << "GuardMode" << RESET << std::endl;
	}
	else
		std::cout << "ScavTrap " << BOLD_ON BLUE << this->getName() << RESET << " is already in " << BOLD_ON << "GuardMode" << RESET << std::endl;
}

void ScavTrap::actionWrapperScav(ScavTrap &eRobot, unsigned int value, unsigned int func) {
	switch (func) {
		case(ATTACK):
			eRobot.attack("Brakis");
			break;
		case(TAKEDAMAGE):
			eRobot.takeDamage(value);
			break;
		case(REPAIRED):
			eRobot.beRepaired(value);
			break;
		case(GUARD):
			eRobot.guardGate();
			break;
		default:
			std::cout << "No action!" << std::endl;
			break;
	}
}

void ScavTrap::run(ClapTrap &iRobot, ScavTrap &eRobot) {
	std::cout << iRobot;
	std::cout << BOLD_ON << "-----------------------------" << RESET << std::endl;
	std::cout << eRobot;
	bool turn = true;
	std::srand(std::time(0));

	while(iRobot.getHitPoint() > 0 && eRobot.getHitPoint() > 0)
	{
		if (turn)
		{
			unsigned int randomValue = (std::rand() % 10) + 1;
			unsigned int randomAction = (std::rand() % 3) + 1;
			std::cout << BOLD_ON << "-----------------------------" << RESET << std::endl;
			iRobot.actionWrapper(iRobot, randomValue, randomAction);
			turn = false;
			std::cout << iRobot;
			sleep (1);
		}
		else
		{
			unsigned int randomValue = (std::rand() % 30) + 1;
			unsigned int randomAction = (std::rand() % 4) + 1;
			std::cout << BOLD_ON << "-----------------------------" << RESET << std::endl;
			eRobot.actionWrapperScav(eRobot, randomValue, randomAction);
			turn = true;
			std::cout << eRobot;
			sleep (1);
		}
	}
}
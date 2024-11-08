/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:23:40 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/08 16:09:38 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <climits>

/*--------------------------------------------------------ORTHODOX CANONICAL FORM---------------------------------------------------------*/

FragTrap::FragTrap() {
	std::cout << BOLD_ON GREEN << "Default (FRAG) constructor called!" << RESET << std::endl;
	this->_name = "defaultFrag";
	this->_hitPoint = 100;
	this->_energyPoint = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string const name) : ClapTrap(name) {
	std::cout << BOLD_ON YELLOW << "Custom (FRAG) constructor called!" << RESET << std::endl;
	this->_hitPoint = 100;
	this->_energyPoint = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
	std::cout << BOLD_ON YELLOW << "Copy (FRAG) constructor called!" << RESET << std::endl;
	*this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	std::cout << BOLD_ON YELLOW << "Copy (FRAG) assigment called!" << RESET << std::endl;
	if (this != &other)
	{
		this->_name = other.getName();
		this->_hitPoint = other.getHitPoint();
		this->_energyPoint = other.getEnergyPoint();
		this->_attackDamage = other.getAttackDamage();
	}
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << BOLD_ON RED << "Destructor (FRAG) called!" << RESET << std::endl;
}

/*---------------------------------------------------------OVERLOAD OP--------------------------------------------------------------------*/

std::ostream& operator<<(std::ostream& out, const FragTrap& frag) {
	out << BOLD_ON << "My name is " << frag.getName() << RESET << std::endl
	<< BOLD_ON << "Hit point --> " << frag.getHitPoint() << RESET << std::endl
	<< BOLD_ON << "Energy point --> " << frag.getEnergyPoint() << RESET << std::endl
	<< BOLD_ON << "Attack damage --> " << frag.getAttackDamage() << RESET << std::endl;
	return (out);
}

/*---------------------------------------------------------FUNCTIONS----------------------------------------------------------------------*/

void FragTrap::highFivesGuys(void) {
	std::cout << BOLD_ON BLUE << this->getName() << RESET << " gives you a high five 👋" << std::endl;
}

void FragTrap::run(ClapTrap& iRobot, ScavTrap& eRobot, FragTrap& fRobot) {
	std::cout << iRobot;
	std::cout << BOLD_ON << "-----------------------------" << RESET << std::endl;
	std::cout << eRobot;
	std::cout << BOLD_ON << "-----------------------------" << RESET << std::endl;
	std::cout << fRobot;
	std::cout << BOLD_ON << "-----------------------------" << RESET << std::endl;
	unsigned int turn = 0;
	std::srand(std::time(0));
	
	static const struct {
		int value_mod;
		int action_mod;
	} map[] = {
		{10, 3},
		{30, 4},
		{40, 4},
	};

	while(iRobot.getHitPoint() > 0 && eRobot.getHitPoint() > 0 && fRobot.getHitPoint() > 0)
	{
		turn = (turn + 1) % 3;
		unsigned int randomValue = (std::rand() % map[turn].value_mod) + 1;
		unsigned int randomAction = (std::rand() % map[turn].action_mod) + 1;
		if (randomAction > INT_MAX || randomValue > INT_MAX)
			break;
		std::cout << BOLD_ON << "-----------------------------" << RESET << std::endl;
		switch (turn) {
			case(CLAPTRAP): {
				iRobot.actionWrapper(iRobot, randomValue, randomAction);
				std::cout << iRobot;
				break;
			}
			case(SCAVTRAP): {
				eRobot.actionWrapperScav(eRobot, randomValue, randomAction);
				std::cout << eRobot;
				break;
			}
			case(FRAGTRAP): {
				fRobot.actionWrapperFrag(fRobot, randomValue, randomAction);
				std::cout << fRobot;
				break;
			}
			default:
				break;
		}
		sleep (1);
	}
}

void FragTrap::actionWrapperFrag(FragTrap &fRobot, unsigned int value, unsigned int func) {
	switch (func) {
		case(ATTACK):
			fRobot.attack("Brakis");
			break;
		case(TAKEDAMAGE):
			fRobot.takeDamage(value);
			break;
		case(REPAIRED):
			fRobot.beRepaired(value);
			break;
		case(HF):
			fRobot.highFivesGuys();
			break;
		default:
			std::cout << "No action!" << std::endl;
			break;
	}
}

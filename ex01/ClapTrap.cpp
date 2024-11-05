/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:44:15 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/05 14:58:14 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*--------------------------------------------------------ORTHODOX CANONICAL FORM---------------------------------------------------------*/

ClapTrap::ClapTrap() {
	std::cout << BOLD_ON GREEN << "Default (CLAP) constructor called!" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string const name) : _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0) {
	std::cout << BOLD_ON YELLOW << "Custom (CLAP) constructor called!" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) {
	std::cout << BOLD_ON YELLOW << "Copy (CLAP) constructor called!" << RESET << std::endl;
	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	std::cout << BOLD_ON YELLOW << "Copy (CLAP) assigment called!" << RESET << std::endl;
	if (this != &other)
	{
		this->_name = other.getName();
		this->_hitPoint = other.getHitPoint();
		this->_energyPoint = other.getEnergyPoint();
		this->_attackDamage = other.getAttackDamage();
	}
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << BOLD_ON RED << "Destructor (CLAP) called!" << RESET << std::endl;
}

/*-----------------------------------------------------GETRER - SETTER -----------------------------------------------------------------*/

std::string ClapTrap::getName(void)const {
	return (this->_name);
}

unsigned int ClapTrap::getHitPoint(void)const {
	return (this->_hitPoint);
}

unsigned int ClapTrap::getEnergyPoint(void)const {
	return (this->_energyPoint);
}

unsigned int ClapTrap::getAttackDamage(void)const {
	return (this->_attackDamage);
}

void ClapTrap::setHitPoint(unsigned int value){
	this->_hitPoint = value;
}

void ClapTrap::setEnergyPoint(unsigned int value) {
	this->_energyPoint = value;
}

/*---------------------------------------------------------FUNCTIONS----------------------------------------------------------------------*/

void ClapTrap::attack(const std::string &target) {
	unsigned int oldEnergyPoint = this->getEnergyPoint();

	if (this->getEnergyPoint() == 0)
	{
		std::cout << BOLD_ON RED << "No more energy! Can't do anything!" << RESET << std::endl;
		return;
	}
	this->setEnergyPoint(oldEnergyPoint - 1);
	std::cout << "Claptrap " << BOLD_ON BLUE << this->getName() << RESET << " attacks " << BOLD_ON YELLOW << target << RESET << ", causing " << BOLD_ON RED << this->getAttackDamage() << RESET << " points of damage!" << std::endl;
	
}

void ClapTrap::takeDamage(unsigned int amount) {
	unsigned int oldHitpoint = this->getHitPoint();
	
	std::cout << "Claptrap " << BOLD_ON BLUE << this->getName() << RESET << " took " << RED << amount << RESET << " damage" << std::endl;
	if (amount >= oldHitpoint) {
		std::cout << BOLD_ON RED << "No more hit points!" << RESET << std::endl;
		this->setHitPoint(0);
	}
	else
		this->setHitPoint(oldHitpoint - amount);
}

void ClapTrap::beRepaired(unsigned int amount) {
	unsigned int oldHitPoint = this->getHitPoint();
	unsigned int maxHitPoint = 10;
	unsigned int oldEnergyPoint = this->getEnergyPoint();
	
	if (this->getEnergyPoint() == 0)
	{
		std::cout << BOLD_ON RED << "No more energy! Can't do anything!" << RESET << std::endl;
		return;
	}
	this->setEnergyPoint(oldEnergyPoint - 1);
	std::cout << "Claptrap " << BOLD_ON BLUE << this->getName() << RESET << " repaired " << RED << amount << RESET << " hit points!" << std::endl;
	if (oldHitPoint + amount > maxHitPoint)
		this->setHitPoint(10);
	else
		this->setHitPoint(oldHitPoint + amount);
}
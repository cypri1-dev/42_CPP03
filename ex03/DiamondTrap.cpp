/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:05:12 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/08 16:21:07 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

/*--------------------------------------------------------ORTHODOX CANONICAL FORM---------------------------------------------------------*/

DiamondTrap::DiamondTrap() {
	std::cout << BOLD_ON GREEN << "Default (DIAMOND) constructor called!" << RESET << std::endl;
	this->_name = "defaultDiamond";
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDamage = 30;
	// code under should theorically work (cheked with CPP) - but actually doesnt ! Try it !
	
	// this->_hitPoint = FragTrap::_hitPoint;
	// this->_energyPoint = ScavTrap::_energyPoint;
	// this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(std::string const name) : ClapTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), _name(name) {
	std::cout << BOLD_ON YELLOW << "Custom (DIAMOND) constructor called!" << RESET << std::endl;
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDamage = 30;
}


DiamondTrap::DiamondTrap(const DiamondTrap &other) {
	*this = other;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
	if (this != &other)
	{
		this->_name = other.getName();
		this->_hitPoint = other.getHitPoint();
		this->_energyPoint = other.getEnergyPoint();
		this->_attackDamage = other.getAttackDamage();
	}
	return (*this);
}

DiamondTrap::~DiamondTrap() {
	std::cout << BOLD_ON RED << "Destructor (DIAMOND) called!" << RESET << std::endl;
}

/*-----------------------------------------------------GETRER - SETTER -----------------------------------------------------------------*/

std::string DiamondTrap::getName(void)const {
	return (this->_name);
}

/*---------------------------------------------------------OVERLOAD OP--------------------------------------------------------------------*/

std::ostream& operator<<(std::ostream &out, const DiamondTrap& diamond) {
	out << BOLD_ON << "My name is " << diamond.getName() << RESET << std::endl
	<< BOLD_ON << "Hit point --> " << diamond.getHitPoint() << RESET << std::endl
	<< BOLD_ON << "Energy point --> " << diamond.getEnergyPoint() << RESET << std::endl
	<< BOLD_ON << "Attack damage --> " << diamond.getAttackDamage() << RESET << std::endl;
	return (out);
}

/*---------------------------------------------------------FUNCTIONS----------------------------------------------------------------------*/

void DiamondTrap::whoAmI() {
	std::cout << "I am " << BOLD_ON BLUE << this->_name << RESET << " and my ClapTrap name is " << BOLD_ON BLUE << this->ClapTrap::getName() << RESET << std::endl;
}

void DiamondTrap::attack(const std::string &target) {
	ScavTrap::attack(target);
}
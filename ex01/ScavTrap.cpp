/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:51:30 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/05 15:07:57 by cyferrei         ###   ########.fr       */
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

ScavTrap &ScavTrap::operator=(const ScavTrap other) {

};
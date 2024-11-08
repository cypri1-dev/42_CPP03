/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:48:57 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/08 16:37:37 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main (void)
{
	ClapTrap iRobot("Wall_E 🤖");
	ScavTrap eRobot("Ultron 💻");
	FragTrap fRobot("R2-D2 🛸");
	DiamondTrap dRobot("Astro Boy 💎");
	
	std::cout << iRobot;
	std::cout << BOLD_ON << "-----------------------------" << RESET << std::endl;
	std::cout << eRobot;
	std::cout << BOLD_ON << "-----------------------------" << RESET << std::endl;
	std::cout << fRobot;
	std::cout << BOLD_ON << "-----------------------------" << RESET << std::endl;
	std::cout << dRobot;
	std::cout << BOLD_ON << "-----------------------------" << RESET << std::endl << std::endl;
	
	std::cout << BOLD_ON BLUE << "CLAPTRAP TESTS - Wall_E 🤖" << RESET << std::endl;
	iRobot.attack("Brakis");
	iRobot.takeDamage(3);
	std::cout << iRobot;
	iRobot.beRepaired(4);
	std::cout << iRobot;
	std::cout << BOLD_ON << "-----------------------------" << RESET << std::endl << std::endl;

	std::cout << BOLD_ON BLUE << "SCAVTRAP TESTS - Ultron 💻" << RESET << std::endl;
	eRobot.attack("Brakis");
	eRobot.takeDamage(12);
	std::cout << eRobot;
	eRobot.beRepaired(13);
	eRobot.guardGate();
	std::cout << eRobot;
	std::cout << BOLD_ON << "-----------------------------" << RESET << std::endl << std::endl << std::endl;
	
	std::cout << BOLD_ON BLUE << "FRAGTRAP TESTS - R2-D2 🛸" << RESET << std::endl;
	fRobot.attack("Brakis");
	fRobot.takeDamage(99);
	std::cout << fRobot;
	fRobot.beRepaired(2);
	std::cout <<fRobot;
	fRobot.highFivesGuys();
	std::cout << BOLD_ON << "-----------------------------" << RESET << std::endl << std::endl << std::endl;
	
	std::cout << BOLD_ON BLUE << "DIAMONDTRAP TESTS - Astro Boy 💎" << RESET << std::endl;
	dRobot.attack("Brakis");
	dRobot.takeDamage(99);
	std::cout << dRobot;
	dRobot.beRepaired(2);
	std::cout << dRobot;
	dRobot.whoAmI();
	std::cout << BOLD_ON << "-----------------------------" << RESET << std::endl << std::endl << std::endl;

	return (0);
}
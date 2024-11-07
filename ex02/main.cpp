/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:48:57 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/07 16:57:46 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main (void)
{
	ClapTrap iRobot("Wall_E 🤖");
	ScavTrap eRobot("Ultron 💻");
	FragTrap fRobot("R2-D2 🛸");
	
	fRobot.run(iRobot, eRobot, fRobot);
	return (0);
}
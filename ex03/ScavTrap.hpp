/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:51:48 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/08 11:18:58 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap { // here s the trick for diamond case!
	private:
		bool _guardMode;
	public :
		ScavTrap();
		ScavTrap(std::string const name);
		ScavTrap(const ScavTrap &other);
		ScavTrap &operator=(const ScavTrap other);
		~ScavTrap();
		void attack(std::string const &target);
		void guardGate(void);

		bool getGuardMode(void)const;
		void setGuardMode(void);

		void run(ClapTrap &iRobot, ScavTrap &eRobot);
		void actionWrapperScav(ScavTrap &eRobot, unsigned int value, unsigned int function);
};

std::ostream& operator<<(std::ostream& out, const ScavTrap& scav);

#endif
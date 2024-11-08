/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:23:43 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/08 11:19:48 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

#define CLAPTRAP 0
#define SCAVTRAP 1
#define FRAGTRAP 2

#define HF 4

class FragTrap : virtual public ClapTrap { // here s the trick for diamond case!
	public:	
		FragTrap();
		FragTrap(std::string const name);
		FragTrap(const FragTrap &other);
		FragTrap &operator=(const FragTrap &other);
		~FragTrap();
		
		void highFivesGuys(void);
		void run(ClapTrap& iRobot, ScavTrap& eRobot, FragTrap& fRobot);
		void actionWrapperFrag(FragTrap &FragTrap, unsigned int value, unsigned int func);
};

std::ostream& operator<<(std::ostream& out, const FragTrap& frag);

#endif
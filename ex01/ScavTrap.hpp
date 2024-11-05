/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:51:48 by cyferrei          #+#    #+#             */
/*   Updated: 2024/11/05 16:08:58 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	private:
		bool _guardMode;
	public :
		ScavTrap();
		ScavTrap(std::string const name);
		ScavTrap(const ScavTrap &other);
		ScavTrap &operator=(const ScavTrap other);
		virtual ~ScavTrap();
		void attack(std::string const &target);
		void guardGate(void);
};

#endif
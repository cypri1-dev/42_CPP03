/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyferrei <cyferrei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:17:32 by cyferrei          #+#    #+#             */
/*   Updated: 2024/10/31 17:29:59 by cyferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <climits>

#define BOLD_ON "\033[1m"
#define BOLD_OFF "\033[0m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define BLUE "\033[34m"

#define ATTACK 1
#define TAKEDAMAGE 2
#define REPAIRED 3

class ClapTrap {
	private:
		std::string _name;
		unsigned int _hitPoint;
		unsigned int _energyPoint;
		unsigned int _attackDamage;
		
	public:
		ClapTrap();
		ClapTrap(std::string const name);
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);
		~ClapTrap();
		
		std::string getName(void)const;
		unsigned int getHitPoint(void)const;
		unsigned int getEnergyPoint(void)const;
		unsigned int getAttackDamage(void)const;
		
		void setHitPoint(unsigned int value);
		void setEnergyPoint(unsigned int value);
		
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void run(void);
		void actionWrapper(unsigned int value, int func);
};

#endif
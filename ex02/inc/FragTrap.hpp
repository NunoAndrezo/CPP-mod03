#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "../inc/ClapTrap.hpp"
#include <iostream>
#include <string>

class FragTrap : public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(FragTrap const &other);
		FragTrap &operator=(FragTrap const &other);
		FragTrap(std::string name);	// needs to print a message to show it was called
		~FragTrap(void);	// needs to print a message to show it was called
		
		void attack(const std::string &target); // cost 1 energy
		void beRepaired(unsigned int amount);
		void takeDamage(unsigned int amount); // cost 1 energy
		// all these functions need to print a message (ex: attack): FragTrap <Name> attacks <target>, causing <damage> points of damage!
		std::string getName(void);
		int getHitPoints(void);
		int getAttackDamage(void);
		int getEnergyPoints(void);
		void highFivesGuys(void);
};

#endif
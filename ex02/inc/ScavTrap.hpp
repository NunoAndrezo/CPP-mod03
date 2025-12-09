#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "../inc/ClapTrap.hpp"
#include <iostream>
#include <string>

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(ScavTrap const &other);
		ScavTrap &operator=(ScavTrap const &other);
		ScavTrap(std::string name);	// needs to print a message to show it was called
		~ScavTrap(void);	// needs to print a message to show it was called
		
		void attack(const std::string &target); // cost 1 energy
		void beRepaired(unsigned int amount);
		void takeDamage(unsigned int amount); // cost 1 energy
		// all these functions need to print a message (ex: attack): ScavTrap <Name> attacks <target>, causing <damage> points of damage!
		std::string getName(void);
		int getHitPoints(void);
		int getAttackDamage(void);
		int getEnergyPoints(void);
		void guardGate();
};

#endif
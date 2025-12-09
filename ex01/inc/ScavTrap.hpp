#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

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
		std::string getName(void);
		void guardGate();
};

#endif

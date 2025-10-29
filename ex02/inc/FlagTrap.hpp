#ifndef FLAGTRAP_HPP
#define FLAGTRAP_HPP

#include <iostream>
#include <string>

class FlagTrap
{
	private:
		std::string		name;
		unsigned int	hit_points;
		unsigned int	energy_points;
		unsigned int	attack_damage;
	public:
		FlagTrap(void);
		FlagTrap(const FlagTrap &other);
		FlagTrap &operator=(const FlagTrap &other);
		FlagTrap(std::string name);	// needs to print a message to show it was called
		~FlagTrap(void);	// needs to print a message to show it was called
		
		void attack(const std::string &target); // cost 1 energy
		void beRepaired(unsigned int amount);
		void takeDamage(unsigned int amount); // cost 1 energy
		// all these functions need to print a message (ex: attack): FlagTrap <Name> attacks <target>, causing <damage> points of damage!
		std::string getName(void);
		int getHitPoints(void);
		int getAttackDamage(void);
		int getEnergyPoints(void);
		void highFivesGuys(void);
};

#endif
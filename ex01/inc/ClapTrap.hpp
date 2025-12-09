#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>


class ClapTrap
{
	protected:
		std::string	name;
		int	hit_points;
		int	energy_points;
		int	attack_damage;
	public:
		ClapTrap(void);
		ClapTrap(std::string name);	// needs to print a message to show it was called
		ClapTrap(ClapTrap const  &other);
		ClapTrap &operator=(ClapTrap const &other);
		virtual ~ClapTrap(void);	// needs to print a message to show it was called

		virtual void attack(const std::string &target); // cost 1 energy
		void beRepaired(unsigned int amount);
		void takeDamage(unsigned int amount); // cost 1 energy
		// all these functions need to print a message (ex: attack): ClapTrap <Name> attacks <target>, causing <damage> points of damage!
		std::string getName(void);
		int getHitPoints(void);
		int getAttackDamage(void);
		int getEnergyPoints(void);
};

#endif
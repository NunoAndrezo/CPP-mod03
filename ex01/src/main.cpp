#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"

int	main(void)
{
	ClapTrap	bot1("Banana");
	ClapTrap	bot2("Monkey");
	ScavTrap	bot4("Maximillion Pegasus");
	ScavTrap	bot3("Seto Kaiba");

	bot1.attack(bot2.getName());
	bot2.takeDamage(20);
	bot2.beRepaired(1);

	bot1.attack(bot2.getName());
	bot2.attack(bot1.getName());
	
	bot3.attack(bot4.getName());
	bot4.takeDamage(20);
	bot4.beRepaired(1);

	bot4.guardGate();
	bot3.attack(bot4.getName());
	bot4.attack(bot3.getName());

	// a construcao / destrucao e feota por chao e depois paredes, 
	return (0);
}
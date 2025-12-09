#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"

int	main(void)
{
	ClapTrap	bot1_ClapTrap("Clapping Banana");
	ClapTrap	bot2_ClapTrap("Clapping Monkey");
	ScavTrap	bot4_ScavTrap("Scav Maximillion Pegasus");
	ScavTrap	bot3_ScavTrap("Scav Seto Kaiba");

	bot1_ClapTrap.attack(bot2_ClapTrap.getName());

	std::cout << "\n @@ Taking Damage starts! @@\n";
	for (int i = 0; i < 5; i++)
	{
		bot2_ClapTrap.takeDamage(20);
	}
	bot2_ClapTrap.beRepaired(1);

	bot1_ClapTrap.attack(bot2_ClapTrap.getName());
	bot2_ClapTrap.attack(bot1_ClapTrap.getName());
	
	bot3_ScavTrap.attack(bot4_ScavTrap.getName());
	std::cout << "\n @@ Taking Damage starts! @@\n";
	for (int i = 0; i < 5; i++)
	{
		bot4_ScavTrap.takeDamage(20);
	}	
	bot4_ScavTrap.beRepaired(1); 

	bot4_ScavTrap.guardGate();
	bot3_ScavTrap.attack(bot4_ScavTrap.getName());
	bot4_ScavTrap.attack(bot3_ScavTrap.getName());

	// a construcao / destrucao e feota por chao e depois paredes, 
	return (0);
}
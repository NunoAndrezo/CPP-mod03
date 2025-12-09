#include "../inc/ClapTrap.hpp"

int main(void)
{
	ClapTrap a("Bob");
	ClapTrap b("Jim");

	a.attack("Jim");
	b.takeDamage(5);
	b.beRepaired(3);
}

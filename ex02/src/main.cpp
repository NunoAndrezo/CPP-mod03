#include "../inc/ClapTrap.hpp"
#include "../inc/ScavTrap.hpp"
#include "../inc/FragTrap.hpp"   // you called it FlagTrap but the exercise requires "FragTrap"

int main()
{
	std::cout << "\n========== TEST 1: BASIC CONSTRUCTION ==========\n";
	ClapTrap a("CLAPPY");
	ScavTrap b("SCAVVY");
	FragTrap c("FRAGGY");

	std::cout << "\n========== TEST 2: COPY CONSTRUCTOR ==========\n";
	ClapTrap a_copy(a);
	ScavTrap b_copy(b);
	FragTrap c_copy(c);

	std::cout << "\n========== TEST 3: COPY ASSIGNMENT ==========\n";
	ClapTrap a_assign;
	ScavTrap b_assign;
	FragTrap c_assign;

	a_assign = a;
	b_assign = b;
	c_assign = c;

	std::cout << "\n========== TEST 4: ATTACK / DAMAGE / REPAIR ==========\n";
	a.attack("Dummy");
	b.attack("Dummy");
	c.attack("Dummy");

	a.takeDamage(5);
	b.takeDamage(20);
	c.takeDamage(30);

	a.beRepaired(3);
	b.beRepaired(10);
	c.beRepaired(15);

	std::cout << "\n========== TEST 5: SPECIAL ABILITIES ==========\n";
	b.guardGate();     // ScavTrap special ability
	c.highFivesGuys(); // FragTrap special ability

	std::cout << "\n========== TEST 6: CHAIN DESTRUCTION ==========\n";
	// end of scope → destructors will run in correct order

	return 0;
}

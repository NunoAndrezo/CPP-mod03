#include "../inc/ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "Constructor from scav was called\n";
}

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "Default Constructor from scav was called\n";
}

// Copy constructor
ScavTrap::ScavTrap(ScavTrap const &other) : ClapTrap(other)
{
	std::cout << "ScavTrap: Copy Constructor was called\n";
	this->hit_points = other.hit_points;
	this->energy_points = other.energy_points;
	this->attack_damage = other.attack_damage;
}

// Copy assignment operator
ScavTrap &ScavTrap::operator=(ScavTrap const &other)
{
	std::cout << "ScavTrap: Copy Assignment Operator was called\n";
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Default Destructor from scav was called\n";
}

std::string	ScavTrap::getName(void)
{
	return (this->name);
}
int	ScavTrap::getHitPoints(void){return (this->hit_points);}

int	ScavTrap::getAttackDamage(void){return (this->attack_damage);}

int	ScavTrap::getEnergyPoints(void){return (this->energy_points);}

void ScavTrap::guardGate(void)
{
	if (this->hit_points <= 0)
		return ;
	std::cout << this->name <<" :🛡️  Gate Keeper mode activated 🛡️\n";
}

void ScavTrap::attack(const std::string &target) // cost 1 energy
{
	std::cout << this->getName() << " has: " << this->getEnergyPoints() << " EP. (From Scav)\n";
	if(this->energy_points <= 0)
		{std::cout << "Not enough EP, you feel tired, so you take a nap... (From Scav)\n"; return;}
	if(this->hit_points <= 0)
		{std::cout << "Not enough HP, you fall to the ground and bleed out... You are dead (From Scav)\n"; return;}
	std::cout << "Used 1 EP to attack!\n";
	std::cout << this->getName() << " attacks " << target << ", inflicting "<< this->getAttackDamage() << " point/s of damage! (From Scav)\n";
	this->energy_points--;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (amount <= 0)
		return ;
	if (this->hit_points <= 0)
		return (std::cout << "ScavTrap " << this->getName() << " is already dead\n", (void)amount);
	this->hit_points -= amount;
	std::cout << "ScavTrap " << this->getName() << " loses "<< amount << " HP!\n";
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (amount <= 0)
		return ;
	std::cout << this->getName() << " has: " << this->getEnergyPoints() << " EP. (From Scav)\n";
	if(this->energy_points <= 0)
		{std::cout << "Not enough EP, you feel tired, so you take a nap... (From Scav)\n"; return;}
	if(this->hit_points <= 0)
		{std::cout << "Not enough HP, you fall to the ground and bleed out... You are dead (From Scav)\n"; return;}
	std::cout << "ScavTrap " << this->getName() << " uses repair. And was able to regaining "<< amount << " HP! (From Scav)\n";
	std::cout << this->getName() << " used 1 EP (From Scav)\n";
	this->energy_points--;
	this->hit_points += amount;
}

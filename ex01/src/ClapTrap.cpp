#include "../inc/ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
	this->name = name;
	std::cout << "Constructor (with name) from ClapTrap was called\n";
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Default Destructor from ClapTrap was called\n";
}

ClapTrap::ClapTrap(void)
{
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
	this->name = "";
	std::cout << "Default Constructor from ClapTrap was called\n";
}

// Copy constructor
ClapTrap::ClapTrap(ClapTrap const &other)
{
	std::cout << "Copy Constructor from ClapTrap was called\n";
	this->name = other.name;
	this->hit_points = other.hit_points;
	this->energy_points = other.energy_points;
	this->attack_damage = other.attack_damage;
}

// Copy assignment operator
ClapTrap &ClapTrap::operator=(ClapTrap const &other)
{
	std::cout << "Copy Assignment Operator from ClapTrap was called\n";
	if (this != &other)
	{
		this->name = other.name;
		this->hit_points = other.hit_points;
		this->energy_points = other.energy_points;
		this->attack_damage = other.attack_damage;
	}
	return *this;
}

std::string	ClapTrap::getName(void)
{
	return (this->name);
}
int	ClapTrap::getHitPoints(void){return (this->hit_points);}

int	ClapTrap::getAttackDamage(void){return (this->attack_damage);}

int	ClapTrap::getEnergyPoints(void){return (this->energy_points);}

void ClapTrap::attack(const std::string &target) // cost 1 energy
{
	if(this->hit_points <= 0)
		{std::cout << "Not enough HP... You are dead! from ClapTrap\n"; return;}
	if(this->energy_points <= 0)
		{std::cout << "Not enough EP, you feel tired, so you take a nap... from ClapTrap\n"; return;}
	std::cout << this->getName() << " has: " << this->getEnergyPoints() << " EP. from ClapTrap\n";
	std::cout << "Used 1 EP to attack! from ClapTrap\n";
	std::cout << this->getName() << " attacks " << target << ", inflicting "<< this->getAttackDamage() << " point/s of damage! from ClapTrap\n";
	this->energy_points--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_points <= 0)
		return (std::cout << "ClapTrap " << this->getName() << " is dead\n", (void)amount);
	this->hit_points -= amount;
	std::cout << "ClapTrap " << this->getName() << " loses "<< amount << "HP\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(this->hit_points <= 0)
		{std::cout << "Not enough HP... You are dead (from Clap)\n"; return;}
	if(this->energy_points <= 0)
		{std::cout << "Not enough EP, you feel tired, so you take a nap... (from Clap)\n"; return;}
	std::cout << this->getName() << " has: " << this->getEnergyPoints() << " EP. (from Clap)\n";
	std::cout << "ClapTrap " << this->getName() << " uses repair. And was able to regaining "<< amount << " HP! (from Clap)\n";
	std::cout << this->getName() << " used 1 EP\n";
	this->energy_points--;
}

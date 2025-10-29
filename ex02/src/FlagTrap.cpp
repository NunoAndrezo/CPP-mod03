#include "../inc/FlagTrap.hpp"

FlagTrap::FlagTrap(std::string name)
{
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	this->name = name;
	std::cout << "Constructor from FlagTrap was called\n";
}

/*
there's a better way to do that:

FlagTrap::FlagTrap(std::string name)
	: name(name), hit_points(100), energy_points(100), attack_damage(30)
{
	std::cout << "Constructor from FlagTrap was called\n";
}
 */

FlagTrap::~FlagTrap(void)
{
	std::cout << "Default Destructor from FlagTrap was called\n";
}

FlagTrap::FlagTrap(void)
{
	std::cout << "Default Constructor from FlagTrap was called\n";
}

// Copy constructor
FlagTrap::FlagTrap(const FlagTrap &other)
{
	std::cout << "FlagTrap: Copy Constructor was called\n";
	this->name = other.name;
	this->hit_points = other.hit_points;
	this->energy_points = other.energy_points;
	this->attack_damage = other.attack_damage;
}

// Copy assignment operator
FlagTrap &FlagTrap::operator=(const FlagTrap &other)
{
	std::cout << "FlagTrap: Copy Assignment Operator was called\n";
	if (this != &other)
	{
		this->name = other.name;
		this->hit_points = other.hit_points;
		this->energy_points = other.energy_points;
		this->attack_damage = other.attack_damage;
	}
	return *this;
}

std::string	FlagTrap::getName(void)
{
	return (this->name);
}

int	FlagTrap::getHitPoints(void){return (this->hit_points);}

int	FlagTrap::getAttackDamage(void){return (this->attack_damage);}

int	FlagTrap::getEnergyPoints(void){return (this->energy_points);}

void	FlagTrap::highFivesGuys(void)
{
	if (this->hit_points == 0)
	{
		std::cout << "FragTrap: " << this->name << " is dead, now he can't high five\n";
		return ;
	}
	std::cout << "FragTrap-> " << this->name << ": Can I get an high five?\n";
}

void FlagTrap::attack(const std::string &target) // cost 1 energy
{
	std::cout << this->getName() << " has: " << this->getEnergyPoints() << " EP. (From Flag)\n";
	if(this->energy_points <= 0)
		{std::cout << "Not enough EP, you feel tired, so you take a nap... (From Flag)\n"; return;}
	if(this->hit_points <= 0)
		{std::cout << "Not enough HP, you fall to the ground and bleed out... You are dead (From Flag)\n"; return;}
	std::cout << "Used 1 EP to attack!\n";
	std::cout << this->getName() << " attacks " << target << ", inflicting "<< this->getAttackDamage() << " point/s of damage! (From Flag)\n";
	this->energy_points--;
}

void FlagTrap::takeDamage(unsigned int amount)
{
	if (this->hit_points <= 0)
		return (std::cout << "FlagTrap " << this->getName() << " is already dead\n", (void)amount);
	if (amount > this->hit_points)
		this->hit_points = 0;
	std::cout << "FlagTrap " << this->getName() << " loses "<< amount << " HP! It's not very effective...\n";
}

void FlagTrap::beRepaired(unsigned int amount)
{
	std::cout << this->getName() << " has: " << this->getEnergyPoints() << " EP. (From Flag)\n";
	if(this->energy_points <= 0)
		{std::cout << "Not enough EP, you feel tired, so you take a nap... (From Flag)\n"; return;}
	if(this->hit_points <= 0)
		{std::cout << "Not enough HP, you fall to the ground and bleed out... You are dead (From Flag)\n"; return;}
	std::cout << "FlagTrap " << this->getName() << " uses repair. And was able to regaining "<< amount << " HP! (From Flag)\n";
	std::cout << this->getName() << " used 1 EP (From Flag)\n";
	this->energy_points--;
}

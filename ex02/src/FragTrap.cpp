#include "../inc/FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << "Constructor from FragTrap was called\n";
}

FragTrap::FragTrap(void) : ClapTrap()
{
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << "Default Constructor from FragTrap was called\n";
}

// Copy constructor
FragTrap::FragTrap(FragTrap const &other) : ClapTrap(other)
{
	std::cout << "FragTrap: Copy Constructor was called\n";
	this->hit_points = other.hit_points;
	this->energy_points = other.energy_points;
	this->attack_damage = other.attack_damage;
}

// Copy assignment operator
FragTrap &FragTrap::operator=(FragTrap const &other)
{
	std::cout << "FragTrap: Copy Assignment Operator was called\n";
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

FragTrap::~FragTrap(void)
{
	std::cout << "Default Destructor from FragTrap was called\n";
}

std::string	FragTrap::getName(void)
{
	return (this->name);
}

int	FragTrap::getHitPoints(void){return (this->hit_points);}

int	FragTrap::getAttackDamage(void){return (this->attack_damage);}

int	FragTrap::getEnergyPoints(void){return (this->energy_points);}

void	FragTrap::highFivesGuys(void)
{
	if (this->hit_points <= 0)
	{
		std::cout << "FragTrap: " << this->name << " is dead, now he can't high five\n";
		return ;
	}
	std::cout << "FragTrap-> " << this->name << ": Can I get an high five?\n";
}

void FragTrap::attack(const std::string &target)// cost 1 energy
{
	std::cout << this->getName() << " has: " << this->getEnergyPoints() << " EP. (From Frag)\n";
	if(this->energy_points <= 0)
		{std::cout << "Not enough EP, you feel tired, so you take a nap... (From Frag)\n"; return;}
	if(this->hit_points <= 0)
		{std::cout << "Not enough HP, you fall to the ground and bleed out... You are dead (From Frag)\n"; return;}
	std::cout << "Used 1 EP to attack!\n";
	std::cout << this->getName() << " attacks " << target << ", inflicting "<< this->getAttackDamage() << " point/s of damage! (From Frag)\n";
	this->energy_points--;
}

void FragTrap::takeDamage(unsigned int amount)
{
	if (amount <= 0)
		return ;
	if (this->hit_points <= 0)
		return (std::cout << "FragTrap " << this->getName() << " is already dead\n", (void)amount);
	this->hit_points -= amount;
	std::cout << "FragTrap " << this->getName() << " loses "<< amount << " HP!\n";
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (amount <= 0)
		return ;
	std::cout << this->getName() << " has: " << this->getEnergyPoints() << " EP. (From Frag)\n";
	if(this->energy_points <= 0)
		{std::cout << "Not enough EP, you feel tired, so you take a nap... (From Frag)\n"; return;}
	if(this->hit_points <= 0)
		{std::cout << "Not enough HP, you fall to the ground and bleed out... You are dead (From Frag)\n"; return;}
	std::cout << "FragTrap " << this->getName() << " uses repair. And was able to regaining "<< amount << " HP! (From Frag)\n";
	std::cout << this->getName() << " used 1 EP (From Frag)\n";
	this->energy_points--;
	this->hit_points += amount;
}

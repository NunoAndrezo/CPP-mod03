#include "../inc/ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
	this->name = "";
	std::cout << "ClapTrap Default Constructor was called\n";
}

ClapTrap::ClapTrap(std::string name)
{
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
	this->name = name;
	std::cout << "ClapTrap Constructor was called\n";
}

// Copy constructor
ClapTrap::ClapTrap(ClapTrap const &other)
{
	std::cout << "ClapTrap  Copy Constructor was called\n";
	this->name = other.name;
	this->hit_points = other.hit_points;
	this->energy_points = other.energy_points;
	this->attack_damage = other.attack_damage;
}

// Copy assignment operator
ClapTrap &ClapTrap::operator=(ClapTrap const &other)
{
	std::cout << "ClapTrap Copy Assignment Operator overload was called\n";
	if (this != &other)
	{
		this->name = other.name;
		this->hit_points = other.hit_points;
		this->energy_points = other.energy_points;
		this->attack_damage = other.attack_damage;
	}
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap Default Destructor was called\n";
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
	std::cout << this->getName() << " has: " << this->getEnergyPoints() << " EP. From ClapTrap\n";
	if(this->energy_points <= 0)
		{std::cout << "Not enough EP, you feel tired, so you take a nap... From ClapTrap\n"; return;}
	if(this->hit_points <= 0)
		{std::cout << "Not enough HP, you fall to the ground and bleed out... You are dead. From ClapTrap\n"; return;}
	std::cout << "Used 1 EP to attack! From ClapTrap\n";
	std::cout << this->getName() << " attacks " << target << ", inflicting "<< this->getAttackDamage() << " point/s of damage! From ClapTrap\n";
	this->energy_points--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount <= 0)
		return ;
	if (this->hit_points <= 0)
		return (std::cout << "ClapTrap " << this->getName() << " is already dead\n", (void)amount);
	this->hit_points -= amount;
	std::cout << "ClapTrap " << this->getName() << " loses "<< amount << " HP!\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (amount <= 0)
		return ;
	std::cout << this->getName() << " has: " << this->getEnergyPoints() << " EP. From ClapTrap\n";
	if(this->energy_points <= 0)
		{std::cout << "Not enough EP, you feel tired, so you take a nap... From ClapTrap\n"; return;}
	if(this->hit_points <= 0)
		{std::cout << "Not enough HP, you fall to the ground and bleed out... You are dead From ClapTrap\n"; return;}
	std::cout << "ClapTrap " << this->getName() << " uses repair. And was able to regaining "<< amount << " HP! From ClapTrap\n";
	std::cout << this->getName() << " used 1 EP. From ClapTrap\n";
	this->energy_points--;
	this->hit_points += amount;
}

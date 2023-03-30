#include "FragTrap.hpp"

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << _name << ": HIGH FIVE GUYS!!!" << std::endl;
}

FragTrap::FragTrap() : ClapTrap("FR4G-TP") {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " default constructor has been called." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " constructor with own name has been called." << std::endl;
}

FragTrap::FragTrap(const FragTrap &origin)  : ClapTrap(origin) {
	std::cout << "FragTrap " << _name << " copy constructor has been called." << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &origin) {
	std::cout << "FragTrap " << _name << " copy assignment operator has been called" << std::endl;

	if (this == &origin)
		return (*this);

	_name = origin._name;
	_hitPoints = origin._hitPoints;
	_energyPoints = origin._energyPoints;
	_attackDamage = origin._attackDamage;
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " destructor has been called." << std::endl;
}
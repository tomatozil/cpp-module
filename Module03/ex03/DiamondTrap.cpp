#include "DiamondTrap.hpp"

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap " << _name << " is also ClapTrap " << ClapTrap::getName() << std::endl;
}

DiamondTrap::DiamondTrap() : _name("DIA4D-TP") {
	ClapTrap::_name = _name + "_clap_name";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	std::cout << "DiamondTrap " << _name << " default constructor has been called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : _name(name) {
	ClapTrap::_name = _name + "_clap_name";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 30;
	std::cout << "DiamondTrap " << _name << " constructor with own name has been called." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& origin) : ClapTrap(origin), ScavTrap(origin), FragTrap(origin) {
	std::cout << "DiamondTrap " << _name << " copy constructor has been called." << std::endl;
//	*this = origin;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& origin) {
	std::cout << "DiamondTrap " << _name << " copy assignment operator has been called" << std::endl;

	if (this == &origin)
		return (*this);

	_name = origin._name;
	ClapTrap::_name = origin.ClapTrap::_name;
	_hitPoints = origin._hitPoints;
	_energyPoints = origin._energyPoints;
	_attackDamage = origin._attackDamage;
	return (*this);
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap " << _name << " destructor has been called." << std::endl;
}


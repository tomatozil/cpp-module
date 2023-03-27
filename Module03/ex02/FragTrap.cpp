#include "FragTrap.hpp"

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << _name << ": HIGH FIVE GUYS!!!" << std::endl;
}

FragTrap::FragTrap() : ClapTrap("FR4G-TP") {
	setHitPoint(100);
	setEnergyPoint(100);
	setAttackDamage(30);
	std::cout << "FragTrap " << _name << " default constructor has been called." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	setHitPoint(100);
	setEnergyPoint(100);
	setAttackDamage(30);
	std::cout << "FragTrap " << _name << " constructor with own name has been called." << std::endl;
}

FragTrap::FragTrap(const FragTrap &origin) {
	std::cout << "FragTrap " << _name << " copy constructor has been called." << std::endl;
	*this = origin;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _name << " destructor has been called." << std::endl;
}
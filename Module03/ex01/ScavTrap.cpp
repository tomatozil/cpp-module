#include "ScavTrap.hpp"

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string &target) {
	if (_energyPoints == 0) {
		std::cout << "ScavTrap " << _name << " has no energy left" << std:: endl;
		return ;
	}
	this->setEnergyPoint(this->getEnergyPoint() - 1);
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

ScavTrap::ScavTrap() : ClapTrap("SC4V-TP") {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " default constructor has been called." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " constructor with own name has been called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &origin) : ClapTrap(origin) {
	std::cout << "ScavTrap " << _name << " copy constructor has been called." << std::endl;
	*this = origin;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << " destructor has been called." << std::endl;
}


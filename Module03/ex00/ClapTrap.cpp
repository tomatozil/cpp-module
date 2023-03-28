#include "ClapTrap.hpp"

void ClapTrap::setName(std::string name) {
	_name = name;
}

void ClapTrap::setHitPoint(unsigned int point) {
	if (point > 10) {
		std::cout << "WARNING: Set fail. Is bigger than limit point" << std::endl;
		return ;
	}
	_hitPoints = point;
}

void ClapTrap::setEnergyPoint(unsigned int point) {
	if (point > 10) {
		std::cout << "WARNING: Set fail. Is bigger than limit point" << std::endl;
		return ;
	}
	_energyPoints = point;
}

void ClapTrap::setAttackDamage(unsigned int damage) {
	if (damage > 5) {
		std::cout << "WARNING: Set fail. Is bigger than limit point" << std::endl;
		return ;
	}
	_attackDamage = damage;
}

std::string ClapTrap::getName() {
	return _name;
}

unsigned int ClapTrap::getHitPoint() {
	return _hitPoints;
}

unsigned int ClapTrap::getEnergyPoint() {
	return _energyPoints;
}

unsigned int ClapTrap::getAttackDamage() {
	return _attackDamage;
}

void ClapTrap::printStatus() {
	std::cout << "  " << _name << "'s status " << std::endl;
	std::cout << "		hit points: " << _hitPoints << std::endl;
	std::cout << "		energy points: " << _energyPoints << std::endl;
	std::cout << "		attack damage: " << _attackDamage << std::endl;
}

void ClapTrap::attack(const std::string &target) {
	if (_energyPoints == 0) {
		std::cout << _name << " has no energy left" << std:: endl;
		return ;
	}
	this->setEnergyPoint(this->getEnergyPoint() - 1);
	std::cout << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << _name << " is already dead." << std:: endl;
		return ;
	}
	if (amount > _hitPoints) {
		this->setHitPoint(0);
		return ;
	}
	this->setHitPoint(this->getHitPoint() - amount);
	std::cout << _name << " gets " << amount << " points of damage,," << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints == 0) {
		std::cout << _name << " has no energy left" << std:: endl;
		return ;
	}
	this->setHitPoint(this->getHitPoint() + amount);
	this->setEnergyPoint(this->getEnergyPoint() - 1);
	std::cout << _name << " is repaired with " << amount << " points! yayyyy☀︎☀︎︎" << std::endl;
}

ClapTrap::ClapTrap() : _name("none"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << "default constructor has been called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << _name << " constructor with own name has been called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &origin) : _name(origin._name), _hitPoints(origin._hitPoints), _energyPoints(origin._energyPoints), _attackDamage(origin._attackDamage) {
	std::cout << "ClapTrap " << _name << " copy constructor has been called." << std::endl;
	*this = origin;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &origin) {
	_name = origin._name;
	_hitPoints = origin._hitPoints;
	_energyPoints = origin._energyPoints;
	_attackDamage = origin._attackDamage;
	std::cout << _name << " copy assignment operator has been called" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " destructor has been called." << std::endl;
}

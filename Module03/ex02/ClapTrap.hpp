#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
public:
	void setName(std::string name);
	void setHitPoint(unsigned int point);
	void setEnergyPoint(unsigned int point);
	void setAttackDamage(unsigned int damage);
	std::string getName();
	unsigned int getHitPoint();
	unsigned int getEnergyPoint();
	unsigned int getAttackDamage();

	void printStatus();

	void attack(const std::string& target); //attack
	void takeDamage(unsigned int amount); //lose hitPoint when attacked
	void beRepaired(unsigned int amount); //get hitPoint back

	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& origin);
	ClapTrap& operator=(const ClapTrap& origin);
	~ClapTrap();

protected:
	std::string _name;
	unsigned int _hitPoints; //when hitPoint or energyPoint is 0, cant do anything
	unsigned int _energyPoints; //lose 1 when attack or repair
	unsigned int _attackDamage;

private:
	static const unsigned int _defaultHP = 100;
	static const unsigned int _defaultEP = 100;
	static const unsigned int _defaultAD = 30;
};

#endif

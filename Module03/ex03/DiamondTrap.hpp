#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, FragTrap {
public:
	void attack(const std::string& target);
	void whoAmI();

	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap& origin);
	DiamondTrap& operator=(const DiamondTrap& origin);
	~DiamondTrap();
private:
	std::string _name;
};

#endif

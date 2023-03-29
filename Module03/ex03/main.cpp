#include "DiamondTrap.hpp"

int main() {
	DiamondTrap dia1("dia1");
	ScavTrap scav1("scav1");
	FragTrap frag1("frag1");

	std::cout << "==========================" << std::endl;
	dia1.attack(scav1.getName());
	scav1.attack(frag1.getName());
	frag1.attack(dia1.getName());

	std::cout << "==========================" << std::endl;
	dia1.whoAmI();
	scav1.guardGate();
	frag1.highFivesGuys();
}
#include "ScavTrap.hpp"

int main() {
	ScavTrap jiyun("jiyun");
	ScavTrap hakim("hakim");
	ScavTrap jujeon;

	jujeon = jiyun;
	jujeon.setName("jujeon");

	jiyun.attack(hakim.getName());
	hakim.takeDamage(jiyun.getAttackDamage());
	jiyun.attack(jujeon.getName());
	jujeon.takeDamage(jiyun.getAttackDamage());

	jiyun.printStatus();
	hakim.printStatus();
	jujeon.printStatus();

	hakim.beRepaired(10);
	jujeon.beRepaired(8);
	hakim.printStatus();
	jujeon.printStatus();

	std::cout << "-------------------------" << std::endl;
	jiyun.setEnergyPoint(100);
	hakim.setHitPoint(100);
	jiyun.printStatus();
	hakim.printStatus();

	jiyun.guardGate();
	hakim.guardGate();
}
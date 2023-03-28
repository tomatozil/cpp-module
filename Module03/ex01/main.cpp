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

	hakim.beRepaired(3);
	jujeon.beRepaired(2);
	hakim.printStatus();
	jujeon.printStatus();

	hakim.setHitPoint(10);
	jiyun.setEnergyPoint(10);
	jiyun.printStatus();
	hakim.printStatus();

	jiyun.guardGate();
	hakim.guardGate();
}
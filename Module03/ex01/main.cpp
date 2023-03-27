#include "ScavTrap.hpp"

int main() {
	ScavTrap jiyun("jiyun");
	jiyun.setAttackDamage(3);
	ScavTrap hakim("hakim");
	hakim.setAttackDamage(2);
	ScavTrap jujeon;
	ScavTrap jiyun2;

	jujeon.setName("jujeon");
	jujeon.setAttackDamage(1);
	jiyun2 = jiyun;
	jiyun2.setName("jiyun2");

	jiyun.attack(hakim.getName());
	jiyun.printStatus();
	hakim.takeDamage(jiyun.getAttackDamage());
	hakim.printStatus();

	jiyun.attack(jujeon.getName());
	jiyun.printStatus();
	jujeon.takeDamage(jiyun.getAttackDamage());
	jujeon.printStatus();

	hakim.beRepaired(3);
	jujeon.beRepaired(11);
	hakim.printStatus();
	jujeon.printStatus();

	jiyun.guardGate();
	hakim.guardGate();
}
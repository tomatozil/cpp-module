#include "ClapTrap.hpp"

int main() {
	ClapTrap jiyun("jiyun");
	jiyun.setAttackDamage(3);
	ClapTrap hakim("hakim");
	hakim.setAttackDamage(2);
	ClapTrap jujeon;

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
	for(int i = 0; i < 5; i++) {
		jiyun.attack(hakim.getName());
		jiyun.printStatus();
		hakim.takeDamage(jiyun.getAttackDamage());
		hakim.printStatus();
	}
}
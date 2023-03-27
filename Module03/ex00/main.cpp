#include "ClapTrap.hpp"

int main() {
	ClapTrap jiyun("jiyun");
	jiyun.setAttackDamage(3);
	ClapTrap hakim("hakim");
	hakim.setAttackDamage(2);
	ClapTrap jujeon;

	jujeon.setName("jujeon");
	jujeon.setAttackDamage(1);

	jiyun.attack(hakim.getName());
	hakim.takeDamage(jiyun.getAttackDamage());
	jiyun.attack(jujeon.getName());
	jujeon.takeDamage(jiyun.getAttackDamage());

	jiyun.printStatus();
	hakim.printStatus();
	jujeon.printStatus();

	hakim.beRepaired(3);
	jujeon.beRepaired(11);
	hakim.printStatus();
	jujeon.printStatus();

	std::cout << "=================================" << std::endl;
	hakim.setHitPoint(24);
	jiyun.setEnergyPoint(-21474);
	for(int i = 0; i < 10; i++) {
		jiyun.attack(hakim.getName());
		jiyun.printStatus();
		hakim.takeDamage(jiyun.getAttackDamage());
		hakim.printStatus();
	}
}
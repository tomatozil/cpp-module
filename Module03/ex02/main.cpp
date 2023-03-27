#include "FragTrap.hpp"

int main() {
	FragTrap jiyun("jiyun");
	jiyun.setAttackDamage(3);
	FragTrap hakim("hakim");
	hakim.setAttackDamage(2);
	FragTrap jujeon;
	FragTrap jiyun2;

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

	hakim.highFivesGuys();
	jujeon.highFivesGuys();
}
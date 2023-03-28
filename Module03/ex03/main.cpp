#include "FragTrap.hpp"

int main() {
	FragTrap jiyun("jiyun");
	FragTrap hakim("hakim");
	FragTrap jujeon;

	jujeon = jiyun;
	jujeon.setName("jujeon");

	jiyun.attack(hakim.getName());
	hakim.takeDamage(jiyun.getAttackDamage());
	jiyun.attack(jujeon.getName());
	jujeon.takeDamage(jiyun.getAttackDamage());

	jiyun.printStatus();
	hakim.printStatus();
	jujeon.printStatus();

	hakim.beRepaired(20);
	jujeon.beRepaired(19);
	hakim.printStatus();
	jujeon.printStatus();

	jiyun.highFivesGuys();
	hakim.highFivesGuys();
}
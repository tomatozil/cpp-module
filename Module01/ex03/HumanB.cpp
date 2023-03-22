#include "HumanB.hpp"

void HumanB::attack() {
	if (!weapon_) {
		std::cout << name_ << " don't have any weapon" << std::endl;
		return ;
	}
	std::cout << name_ << " attacks with his " << weapon_->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
	weapon_ = &weapon;
}

HumanB::HumanB(std::string name) : name_(name), weapon_(0) {}

HumanB::~HumanB() {}


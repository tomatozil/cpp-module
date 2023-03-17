#include "HumanB.hpp"

void HumanB::attack() {
	std::cout << name_ << " attacks with his " << weapon_->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
	weapon_ = &weapon;
}

HumanB::HumanB(std::string name) : name_(name), weapon_(nullptr) {}

HumanB::~HumanB() {}


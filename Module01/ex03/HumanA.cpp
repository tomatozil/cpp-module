#include "HumanA.hpp"

void HumanA::attack() {
	std::cout << name_ << " attacks with his " << weapon_.getType() << std::endl;
}

HumanA::HumanA(std::string name, Weapon &weapon) : name_(name), weapon_(weapon) {}

HumanA::~HumanA() {}
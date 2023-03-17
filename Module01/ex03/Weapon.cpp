#include "Weapon.hpp"

void Weapon::setType(std::string type) {
	this->type_ = type;
}

const std::string& Weapon::getType() {
	const std::string& ref = type_;
	return (ref);
}

Weapon::Weapon(std::string type) : type_(type) {}

Weapon::~Weapon() {}





#include "Cure.hpp"

AMateria* Cure::clone() const {
	return (new Cure());
}

void Cure::use(ICharacter &target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure &origin) : AMateria(origin.type) {}

Cure& Cure::operator=(const Cure &ice) {
	if (this == &ice)
		return (*this);
	type = ice.type;
	return (*this);
}

Cure::~Cure() {}

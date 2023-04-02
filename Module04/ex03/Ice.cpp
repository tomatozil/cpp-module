#include "Ice.hpp"

AMateria* Ice::clone() const {
	return (new Ice());
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &origin) : AMateria(origin.type) {}

Ice& Ice::operator=(const Ice &ice) {
	if (this == &ice)
		return (*this);
	type = ice.type;
	return (*this);
}

Ice::~Ice() {}
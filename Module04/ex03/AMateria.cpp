#include "AMateria.hpp"

std::string const & AMateria::getType() const {
	return (type);
}

void AMateria::use(ICharacter &target) {
	(void)target;
}

AMateria::AMateria() : type("Unknown"){}

AMateria::AMateria(const std::string &type) : type(type) {}

AMateria::AMateria(const AMateria &origin) : type(origin.type) {}

AMateria& AMateria::operator=(const AMateria &materia) {
	if (this == &materia)
		return (*this);
	type = materia.getType();
	return (*this);
}

AMateria::~AMateria() {}
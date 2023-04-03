#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria {
public:
	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria& origin);
	AMateria& operator=(const AMateria& materia);
	virtual ~AMateria();

protected:
	std::string type;
};

#endif

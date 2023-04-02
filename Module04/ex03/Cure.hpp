#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria {
public:
	virtual AMateria* clone() const;
	virtual void use(ICharacter& target);

	Cure();
	Cure(const Cure& origin);
	Cure& operator=(const Cure& ice);
	virtual ~Cure();
};

#endif

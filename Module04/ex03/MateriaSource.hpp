#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
public:
	virtual void learnMateria(AMateria* m);
	virtual AMateria* createMateria(std::string const & type);

	MateriaSource();
	MateriaSource(MateriaSource const & origin);
	MateriaSource& operator=(MateriaSource const & materiaSource);
	virtual ~MateriaSource();

private:
	AMateria* inventory[4];
};

#endif

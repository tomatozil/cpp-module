#include "MateriaSource.hpp"

void MateriaSource::learnMateria(AMateria* m) {
	if (!m) {
		std::cout << "Learn Fail: invalid Materia." << std::endl;
	}
	for(int i = 0; i < 4; i++) {
		if (!inventory[i]) {
			inventory[i] = m;
			return ;
		}
	}
	std::cout << "Learn Fail: inventory is full." << std::endl;
}

AMateria* MateriaSource::createMateria(const std::string &type) {
	for(int i = 0; i < 4; i++)
		if (inventory[i] && inventory[i]->getType() == type)
			return (inventory[i]->clone());
	return (0);
}

MateriaSource::MateriaSource() {
	for(int i = 0; i < 4; i++)
		inventory[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource &origin) {
	for(int i = 0; i < 4; i++) {
		if (origin.inventory[i])
			inventory[i] = origin.inventory[i]->clone();
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource &materiaSource) {
	if (this == &materiaSource)
		return (*this);
	for(int i = 0; i < 4; i++) {
		if (inventory[i])
			delete inventory[i];
		if (materiaSource.inventory[i])
			inventory[i] = materiaSource.inventory[i]->clone();
		else
			inventory[i] = 0;
	}
	return (*this);
}

MateriaSource::~MateriaSource() {
	for(int i = 0; i < 4; i++)
		if (inventory[i])
			delete inventory[i];
}

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

#define N 2

int main() {
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* floor[N];
	for (int i = 0; i < N; i++)
		floor[i]= 0;
	floor[0] = src->createMateria("ice");
	me->equip(floor[0]); // 땅에서 가져감
	floor[1] = src->createMateria("cure");
	me->equip(floor[1]);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	me->unequip(0);
	me->unequip(1);

	delete bob;
	delete me;
	delete src;
//	system("leaks a.out");
	return 0;
}
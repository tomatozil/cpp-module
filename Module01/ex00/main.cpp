#include "Zombie.hpp"

int main() {
	Zombie stack_zombie("stack_zombie");
	Zombie *heap_zombie;

	stack_zombie.announce();
	heap_zombie = Zombie::newZombie("heap_zombie");
	heap_zombie->announce();
	Zombie::randomChump("random_zombie");
	delete heap_zombie;
	return 0;
}

#include "Zombie.hpp"

void Zombie::randomChump(std::string name) {
	Zombie new_zombie(name);
	new_zombie.announce();
}
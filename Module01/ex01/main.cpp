#include "Zombie.hpp"

#define N 9

int main() {
	Zombie *zombies;

	zombies = Zombie::zombieHorde(N, "zombies");
	for(int i = 0; i < N; i++) {
		zombies[i].announce();
	}
	delete[] zombies;
	return 0;
}

#include "Dog.hpp"
#include "Cat.hpp"

#define N 4

int main() {
	Animal *animals[N];

	for(int i = 0; i < N; i++) {
		if (i < N*0.5)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
		animals[i]->makeSound();
	}

	Dog originDog;
	originDog.setBrain("none");
	Cat originCat;
	originCat.setBrain("onoe");

	Dog copyDog(originDog);
	for(int i = 0; i < 5; i++)
		std::cout << copyDog.getBrain().ideas[i] << std::endl;
	Cat copyCat(originCat);
	for(int i = 0; i < 5; i++)
		std::cout << copyCat.getBrain().ideas[i] << std::endl;

	system("leaks a.out");
	return 0;
}
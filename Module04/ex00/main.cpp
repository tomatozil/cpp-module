#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	animal->makeSound();
	dog->makeSound(); //will output the cat sound!
	cat->makeSound();

	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongCat* wrongCat = new WrongCat();

	std::cout << wrongAnimal->getType() << " " << std::endl;
	std::cout << wrongCat->getType() << " " << std::endl;
	wrongAnimal->makeSound();
	wrongCat->makeSound(); //will output the wrong cat sound!

	delete animal;
	delete dog;
	delete cat;
	delete wrongAnimal;
	delete wrongCat;

//	system("leaks a.out");
	return 0;
}
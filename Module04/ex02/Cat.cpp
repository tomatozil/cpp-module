#include "Cat.hpp"

void Cat::makeSound() const {
	std::cout << "MEOW MEOW MEOW MEOW MEOW MEOW MEOW MEOW MEOW MEOW" << std::endl;
}

Cat::Cat()
	: Animal("Cat"), brain(new Brain()) {
	std::cout << type << " default constructor has been called." << std::endl;
}

Cat::Cat(const Cat &origin)
	: Animal(origin), brain(new Brain(*origin.brain)) {
	std::cout << type << " copy constructor has been called." << std::endl;
}

Cat& Cat::operator=(const Cat &cat) {
	std::cout << type << " copy assignment constructor has been called." << std::endl;
	if (this == &cat)
		return (*this);
	type = cat.type;
	*brain = *cat.brain;
	return (*this);
}

Cat::~Cat() {
	std::cout << type << " destructor has been called." << std::endl;
	delete brain;
}
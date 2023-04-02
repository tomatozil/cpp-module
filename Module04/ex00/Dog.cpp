#include "Dog.hpp"

void Dog::makeSound() const {
	std::cout << "BARK BARK BARK BARK BARK BARK BARK BARK BARK BARK" << std::endl;
}

Dog::Dog() : Animal("Dog") {
	std::cout << type << " default constructor has been called." << std::endl;
}

Dog::Dog(const Dog &origin)
	: Animal(origin) {
	std::cout << type << " copy constructor has been called." << std::endl;
}

Dog& Dog::operator=(const Dog &dog) {
	std::cout << type << " copy assignment constructor has been called." << std::endl;
	if (this == &dog)
		return (*this);
	type = dog.type;
	return (*this);
}

Dog::~Dog() {
	std::cout << type << " destructor has been called." << std::endl;
}
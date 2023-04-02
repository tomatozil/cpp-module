#include "Animal.hpp"

std::string Animal::getType() const {
	return (type);
}

Animal::Animal()
	: type("Animal") {
	std::cout << "Animal default constructor has been called." << std::endl;
}

Animal::Animal(std::string type)
	: type(type) {
	std::cout << "Animal constructor with own type has been called." << std::endl;
}

Animal::Animal(const Animal &origin)
	: type(origin.type) {
	std::cout << "Animal copy constructor has been called." << std::endl;
}

Animal& Animal::operator=(const Animal &animal) {
	std::cout << "Animal copy assignment has been called." << std::endl;
	if (this == &animal)
		return (*this);
	type = animal.type;
	return (*this);
}

Animal::~Animal() {
	std::cout << "Animal destructor has been called." << std::endl;
}

#include "WrongAnimal.hpp"

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal also can't cry yet." << std::endl;
}

std::string WrongAnimal::getType() const {
	return (type);
}

WrongAnimal::WrongAnimal()
	: type("WrongAnimal") {
	std::cout << "WrongAnimal default constructor has been called." << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
	: type(type) {
	std::cout << "WrongAnimal constructor with own type has been called." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &origin)
	: type(origin.type) {
	std::cout << "WrongAnimal copy constructor has been called." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &wrongAnimal) {
	std::cout << "WrongAnimal copy assignment has been called." << std::endl;
	if (this == &wrongAnimal)
		return (*this);
	type = wrongAnimal.type;
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor has been called." << std::endl;
}
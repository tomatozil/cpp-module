#include "WrongCat.hpp"

void WrongCat::makeSound() const {
	std::cout << "WRONG MEOW WRONG MEOW WRONG MEOW WRONG MEOW WRONG MEOW" << std::endl;
}

WrongCat::WrongCat()
	: WrongAnimal("WrongCat") {
	std::cout << type << " default constructor has been called." << std::endl;
}

WrongCat::WrongCat(const WrongCat &origin)
	: WrongAnimal(origin) {
	std::cout << type << " copy constructor has been called." << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &wrongCat) {
	std::cout << type << " copy assignment constructor has been called." << std::endl;
	if (this == &wrongCat)
		return (*this);
	type = wrongCat.type;
	return (*this);
}

WrongCat::~WrongCat() {
	std::cout << type << " destructor has been called." << std::endl;
}
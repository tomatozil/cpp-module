#include "Dog.hpp"

void Dog::makeSound() const {
	std::cout << "BARK BARK BARK BARK BARK BARK BARK BARK BARK BARK" << std::endl;
}

void Dog::setBrain(std::string content) {
	for(int i = 0; i < I; i++)
		brain->setContent(content);
}

const Brain& Dog::getBrain() {
	return (*brain);
}

Dog::Dog()
	: Animal("Dog"), brain(new Brain()) {
	std::cout << type << " default constructor has been called." << std::endl;
}

Dog::Dog(const Dog &origin)
	: Animal(origin), brain(new Brain(*origin.brain)) { //shallow copy: brain(new Brain())
	std::cout << type << " copy constructor has been called." << std::endl;
}

Dog& Dog::operator=(const Dog &dog) {
	std::cout << type << " copy assignment constructor has been called." << std::endl;
	if (this == &dog)
		return (*this);
	type = dog.type;
	*brain = *dog.brain;
	return (*this);
}

Dog::~Dog() {
	std::cout << type << " destructor has been called." << std::endl;
	delete brain;
}
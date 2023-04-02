#include "Brain.hpp"

void Brain::setContent(std::string content) {
	for(int i = 0; i < I; i++)
		ideas[i] = content;
}

Brain::Brain()
	: ideas() {
	std::cout << "Brain default constructor has been called." << std::endl;
}

Brain::Brain(std::string type)
	: ideas() {
	std::cout << "Called brain default constructor whth content of ideas." << std::endl;
	for(int i = 0; i < I; i++)
		ideas[i] = type;
}

Brain::Brain(const Brain& origin) {
	for (int i = 0; i < I; i++)
		ideas[i] = origin.ideas[i];
}

Brain& Brain::operator=(const Brain& brain) {
	if (this == &brain)
		return (*this);
	for (int i = 0; i < I; i++)
		ideas[i] = brain.ideas[i];
	return (*this);
}

Brain::~Brain() {
	std::cout << "Brain destructor has been called." << std::endl;
}

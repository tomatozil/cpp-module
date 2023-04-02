#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
public:
	virtual void makeSound() const = 0;
	std::string getType() const;

	Animal();
	Animal(std::string type);
	Animal(const Animal& origin);
	Animal& operator=(const Animal& animal);
	virtual ~Animal();

protected:
	std::string type;
};

#endif

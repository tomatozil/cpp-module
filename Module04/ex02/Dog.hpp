#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
public:
	virtual void makeSound() const;
	Brain* brain;

	Dog();
	Dog(const Dog& origin);
	Dog& operator=(const Dog& dog);
	virtual ~Dog();
};

#endif

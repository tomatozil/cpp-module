#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
public:
	virtual void makeSound() const;
	Brain* brain;

	Cat();
	Cat(const Cat& origin);
	Cat& operator=(const Cat& cat);
	virtual ~Cat();
};

#endif

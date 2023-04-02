#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal {
public:
	virtual void makeSound() const;

	Cat();
	Cat(const Cat& origin);
	Cat& operator=(const Cat& cat);
	virtual ~Cat();
};

#endif

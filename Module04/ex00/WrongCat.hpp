#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
	virtual void makeSound() const;

	WrongCat();
	WrongCat(const WrongCat& origin);
	WrongCat& operator=(const WrongCat& wrongCat);
	~WrongCat();
};

#endif

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
public:
	virtual void makeSound() const;
	std::string getType() const;

	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(const WrongAnimal& origin);
	WrongAnimal& operator=(const WrongAnimal& animal);
	virtual ~WrongAnimal();

protected:
	std::string type;
};

#endif

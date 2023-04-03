#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
public:
	virtual void makeSound() const;
	void setBrain(std::string content);
	const Brain& getBrain();

	Cat();
	Cat(const Cat& origin);
	Cat& operator=(const Cat& cat);
	virtual ~Cat();

private:
	Brain* brain;
};

#endif

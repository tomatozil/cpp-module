#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

#define I 100

class Brain {
public:
	std::string ideas[I];
	void setContent(std::string content);

	Brain();
	Brain(const Brain& origin);
	Brain(std::string type);
	Brain& operator=(const Brain& brain);
	~Brain();
};

#endif

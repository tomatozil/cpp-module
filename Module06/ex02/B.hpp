#ifndef B_HPP
#define B_HPP

#include "Base.hpp"

class B : public Base {
public:
	std::string& getType();
	B();
	~B();

	class CastingErrorException : public std::exception {
		const char * what() const throw();
	};

private:
	std::string type;
};

#endif

#ifndef A_HPP
#define A_HPP

#include "Base.hpp"

class A : public Base {
public:
	std::string& getType();
	A();
	~A();

	class CastingErrorException : public std::exception {
		const char * what() const throw();
	};

private:
	std::string type;
};

#endif

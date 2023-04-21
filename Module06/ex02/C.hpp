#ifndef C_HPP
#define C_HPP

#include "Base.hpp"

class C : public Base {
public:
	std::string& getType();
	C();
	~C();

	class CastingErrorException : public std::exception {
		const char * what() const throw();
	};

private:
	std::string type;
};

#endif

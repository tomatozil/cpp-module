#include "C.hpp"

std::string& C::getType() {
	return type;
}

C::C() : type("C") {}

C::~C() {}

const char* C::CastingErrorException::what() const throw() {
	return ("Trying cast to C-type Fails");
}


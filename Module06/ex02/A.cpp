#include "A.hpp"

std::string& A::getType() {
	return type;
}

A::A() : type("A") {}

A::~A() {}

const char* A::CastingErrorException::what() const throw() {
	return ("Trying cast to A-type Fails");
}
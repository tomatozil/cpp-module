#include "B.hpp"

std::string& B::getType() {
	return type;
}

B::B() : type("B") {}

B::~B() {}

const char* B::CastingErrorException::what() const throw() {
	return ("Trying cast to B-type Fails");
}


#include "A.hpp"

std::string& A::getType() {
	return type;
}

A::A() : type("A") {}

A::~A() {}
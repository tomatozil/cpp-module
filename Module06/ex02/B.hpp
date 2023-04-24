#ifndef B_HPP
#define B_HPP

#include "Base.hpp"

class B : public Base {
public:
	std::string& getType();
	B();
	~B();

private:
	std::string type;
};

#endif

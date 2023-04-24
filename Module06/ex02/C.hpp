#ifndef C_HPP
#define C_HPP

#include "Base.hpp"

class C : public Base {
public:
	std::string& getType();
	C();
	~C();

private:
	std::string type;
};

#endif

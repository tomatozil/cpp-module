#ifndef A_HPP
#define A_HPP

#include "Base.hpp"

class A : public Base {
public:
	std::string& getType();
	A();
	~A();

private:
	std::string type;
};

#endif

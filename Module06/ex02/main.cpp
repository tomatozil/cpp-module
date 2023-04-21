#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate() {
//	std::srand(std::time(NULL));
	int randomNum = std::rand() % 4;
	switch (randomNum) {
		case 0 :
			return new A();
		case 1 :
			return new B();
		default :
			return new C();
	}
}

void identify(Base* p) {
	A* a = dynamic_cast<A*>(p);
	if (a != NULL)
		std::cout << a->getType() << std::endl;
	B* b = dynamic_cast<B*>(p);
	if (b != NULL)
		std::cout << b->getType() << std::endl;
	C* c = dynamic_cast<C*>(p);
	if (c != NULL)
		std::cout << c->getType() << std::endl;
}

void identify(Base& p) {
	try {
		A a = dynamic_cast<A&>(p);
		std::cout << a.getType() << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		B b = dynamic_cast<B&>(p);
		std::cout << b.getType() << std::endl;
		return ;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	try {
		C c = dynamic_cast<C&>(p);
		std::cout << c.getType() << std::endl;
		return ;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

int main() {
	Base* base_ptr1 = generate();
	Base* base_ptr2 = generate();
	Base* base_ptr3 = generate();

	identify(base_ptr1);
	identify(*base_ptr1);

	identify(base_ptr2);
	identify(*base_ptr2);

	identify(base_ptr3);
	identify(*base_ptr3);

	delete base_ptr1;
	delete base_ptr2;
	delete base_ptr3;
}

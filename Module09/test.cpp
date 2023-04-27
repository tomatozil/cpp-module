#include <iostream>
#include <map>

class A {
public:
	A() {
		std::cout << "=== A default constructor ===" << std::endl;
		std::cout << "A memory: " << this << std::endl;
	}
	A(const A& origin) : m(origin.m) {
		std::cout << "=== A copy constructor ===" << std::endl;
		std::cout << "A memory: " << &origin << std::endl;
		std::cout << "A copy memory: " << this << std::endl;
		std::cout << "map in A: " << &origin.m << std::endl;
		std::cout << "map in copy A memory: " << &this->m << std::endl;
	}
	A& operator=(const A& a) {
		std::cout << "=== A copy assignment operator ===" << std::endl;
		if (this->m == a.m) {
			std::cout << "ms are same" << std::endl;
			return (*this);
		}
		this->m = a.m;
		std::cout << "A memory: " << &a << std::endl;
		std::cout << "A copy memory: " << this << std::endl;
		std::cout << "map in A: " << &a.m << std::endl;
		std::cout << "map in copy A memory: " << &this->m << std::endl;
		return (*this);
	}
	~A() {}
private:
	std::map<int, int> m;
};

int main() {
	A a1;
	A a2 = a1;
	A a3(a1);
	A a4;

	a4 = a1;
}
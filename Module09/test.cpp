#include <iostream>
#include <map>

class A {
public:
	A() : i(12) {
		std::cout << "\n=== A default constructor ===" << std::endl;
		std::cout << "A memory: " << this << std::endl;
	}
	A(const A& origin) : m(origin.m), i(origin.i) {
		std::cout << "\n=== A copy constructor ===" << std::endl;
		std::cout << "A memory: " << &origin << std::endl;
		std::cout << "A copy memory: " << this << std::endl;
		std::cout << "map in A: " << &origin.m << std::endl;
		std::cout << "map in copy A memory: " << &this->m << std::endl;
		std::cout << "i in A memory: " << &origin.i << std::endl;
		std::cout << "i in copy A memory: " << &this->i << std::endl;
		std::cout << "m[1] in A: " << origin.m.at(1) << std::endl;
		std::cout << "m[1] in copy A: " << this->m.at(1) << std::endl;
		std::cout << "i in A: " << origin.i << std::endl;
		std::cout << "i in copy A: " << this->i << std::endl;
	}
	A& operator=(const A& a) { //괄호 들어오기 전에 이미 default 생성자로 생성이 되어있었음.
		std::cout << "\n=== A copy assignment operator ===" << std::endl;
//		if (this->i != a.i) {
			std::cout << "i in A: " << a.i << std::endl;
			std::cout << "i in copy A: " << this->i << std::endl;
//			this->i = a.i;
//			std::cout << "[AFTER]i in A: " << a.i << std::endl;
//			std::cout << "[AFTER]i in copy A: " << this->i << std::endl;
			std::cout << "i in A memory: " << &a.i << std::endl;
			std::cout << "i in copy A memory: " << &this->i << std::endl;
//		}
		if (this->m != a.m) {
			std::cout << "map in A memory: " << &a.m << std::endl;
			std::cout << "map in copy A memory: " << &this->m << std::endl;
//			std::cout << "m[1] in A: " << a.m.at(1) << std::endl;
//			std::cout << "m[1] in copy A: " << this->m.at(1) << std::endl;
			this->m = a.m; //내용을 복사하는 일
			std::cout << "[AFTER] map in A memory: " << &a.m << std::endl;
			std::cout << "[AFTER] map in copy A memory: " << &this->m << std::endl;
			std::cout << "[AFTER] m[1] in A: " << a.m.at(1) << std::endl;
			std::cout << "[AFTER] m[1] in copy A: " << this->m.at(1) << std::endl;
		}
		std::cout << "A memory: " << &a << std::endl;
		std::cout << "A copy memory: " << this << std::endl;
		return (*this);
	}
	~A() {}

	void setMapContent(int i1, int i2) {
		m[i1] = i2;
	}

//	void setIContent(int I) {
//		i = I;
//	}

	int getMapContent() {
		return m.at(1);
	}
private:
	std::map<int, int> m;
	const unsigned int  i;
};

int main() {
	A a1;
	a1.setMapContent(1, 2);
//	a1.setIContent(12);
	A a2 = a1;
	A a3(a1);
	A a4;

	a4 = a1;
	std::cout << "\na1 m[1]: " << a1.getMapContent() << std::endl;
	std::cout << "a2 m[1]: " << a2.getMapContent() << std::endl;
	std::cout << "a3 m[1]: " << a3.getMapContent() << std::endl;
	std::cout << "a4 m[1]: " << a4.getMapContent() << std::endl;
}
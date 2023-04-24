#include "Array.hpp"

int main() {
	Array<std::string> a(5);
	try {
		a[0] = "h";
		a[1] = "e";
		a[2] = "l";
		a[3] = "l";
		a[4] = "o";
	} catch (std::range_error& e) {
		std::cout << e.what() << std::endl;
	}

	a.print();

	try {
		a[4] = " yeah";
		a[5] = "!";
	} catch (std::range_error& e) {
		std::cout << e.what() << std::endl;
	}

	a.print();
}
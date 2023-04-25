#include "iter.hpp"

int main() {
	std::string arr[5] = {"h", "e", "l", "l", "o"};

//	try {
//		::iter(arr, -1, ::print);
//	} catch (std::exception& e) {
//		std::cout << e.what() << std::endl;
//	}
	::iter(arr, 5, ::print);
}
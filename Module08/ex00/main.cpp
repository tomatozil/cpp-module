#include "easyfind.hpp"

#include <array>
#include <vector>
#include <list>
#include <deque>

int main() {
	std::array<int, 5> arr = {1, 2, 3, 4, 5};
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	std::list<int> list;
	list.insert(list.begin(), arr.begin(), arr.end());
	std::deque<int> deq;
	deq.insert(deq.begin(), arr.begin(), arr.end());

	std::cout << "test array: \n\t";
	try {
		std::cout << ::easyfind(arr, 5) << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "test vector: \n\t";
	try {
		std::cout << ::easyfind(vec, 5) << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "test list: \n\t";
	try {
		std::cout << ::easyfind(list, 5) << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "test deque: \n\t";
	try {
		std::cout << ::easyfind(deq, 2) << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}


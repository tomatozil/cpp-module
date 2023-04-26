#include "easyfind.hpp"

#include <vector>
#include <list>
#include <deque>

int main() {
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	std::list<int> list;
	list.insert(list.begin(), vec.begin(), vec.end());
	std::deque<int> deq;
	deq.insert(deq.begin(), vec.begin(), vec.end());

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
		std::cout << ::easyfind(deq, 6) << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}


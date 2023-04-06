#include "Bureaucra.hpp"

int main() {
	Bureaucra bureaucra1; // grade = 150으로 자동 설정
	Bureaucra bureaucra2("jiyun", 2);

	std::cout << "1: \n";
	try {
		bureaucra1.decrementGrade();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << bureaucra1 << std::endl;

	std::cout << "\n2: \n";
	try {
		bureaucra2.incrementGrade();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << bureaucra2 << std::endl;

	std::cout << "\n3: \n";
	try {
		bureaucra2.incrementGrade();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << bureaucra2 << std::endl;

	std::cout << "\n4: \n";
	try {
		bureaucra2.decrementGrade();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << bureaucra2 << std::endl;
}

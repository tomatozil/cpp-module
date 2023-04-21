#include "Bureaucrat.hpp"

int main() {
	Bureaucrat bureaucrat1; // grade = 150으로 자동 설정
	Bureaucrat bureaucrat2("jiyun", 2);

	std::cout << "1: \n";
	try {
		bureaucrat1.decrementGrade();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << bureaucrat1 << std::endl;

	std::cout << "\n2: \n";
	try {
		bureaucrat2.incrementGrade();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << bureaucrat2 << std::endl;

	std::cout << "\n3: \n";
	try {
		bureaucrat2.incrementGrade();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << bureaucrat2 << std::endl;

	std::cout << "\n4: \n";
	try {
		bureaucrat2.decrementGrade();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << bureaucrat2 << std::endl;
}

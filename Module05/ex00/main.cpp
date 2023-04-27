#include "Bureaucrat.hpp"

int main() {
	Bureaucrat bureaucrat1; // grade = 150으로 자동 설정
	Bureaucrat bureaucrat2("jiyun", 2);

	std::cout << "1: \n";
	try {
		bureaucrat1.decrementGrade();
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}
	std::cout << bureaucrat1 << "\n";

	std::cout << "2: \n";
	try {
		bureaucrat2.incrementGrade();
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}
	std::cout << bureaucrat2 << "\n";

	std::cout << "3: \n";
	try {
		bureaucrat2.incrementGrade();
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}
	std::cout << bureaucrat2 << "\n";

	std::cout << "4: \n";
	try {
		bureaucrat2.decrementGrade();
	} catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}
	std::cout << bureaucrat2 << "\n";
}

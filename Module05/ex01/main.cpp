#include "Bureaucra.hpp"

int main() {
	Bureaucra bureaucra1; // grade = 150으로 자동 설정
	Bureaucra bureaucra2("jiyun", 2);
	Form form1;
	Form form2("jiyun's form", 10, 10);

	std::cout << form2 << std::endl;
	bureaucra2.signForm(form2);
	std::cout << form2 << std::endl;

	try {
		Form form3("Anyone's", 151, 11);

	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "------------------------------------" << std::endl;

	Form form4;
	try {
		form4 = Form("Anyone's", 149, 11);

	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << form4 << std::endl;
}

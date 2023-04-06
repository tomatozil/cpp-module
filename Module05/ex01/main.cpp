#include "Bureaucra.hpp"

int main() {
	Bureaucra bureaucra1; // grade = 150으로 자동 설정
	Bureaucra bureaucra2("jiyun", 2);
	Form form1;
	Form form2("jiyun's form", 10, 10);

	std::cout << form2 << std::endl;
	bureaucra2.signForm(form2);
	std::cout << form2 << std::endl;

	Form form3;
	try {
		form3 = Form("Anyone's", 151, 11);

	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << form3 << std::endl;
}

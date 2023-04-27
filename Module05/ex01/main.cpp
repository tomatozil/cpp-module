#include "Bureaucrat.hpp"

int main() {
	Bureaucrat bureaucrat1; // grade = 150으로 자동 설정
	Bureaucrat bureaucrat2("jiyun", 2);
	Form form1;
	Form form2("jiyun's form", 10, 10);

	std::cout << form2 << std::endl;
	bureaucrat2.signForm(form2);
	std::cout << form2 << std::endl;

	try {
		Form form3("Anyone's", 151, 11);

	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "------------------------------------" << std::endl;

	Form form4;
	std::cout << "form4's memory: " << &form4 << std::endl;
	try {
		Form formTmp("Anyone's", 149, 11);
		form4 = formTmp;

	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << form4 << std::endl;
	std::cout << "[AFTER]form4's memory: " << &form4 << std::endl;

	std::cout << "------------------------------------" << std::endl;

	Bureaucrat bureaucrat3;
	std::cout << "bureaucrat3's grad: " << bureaucrat3.getGrade() << std::endl;
	try {
		Bureaucrat bureaucratTmp("Anyone's", 130);
		bureaucrat3 = bureaucratTmp;

	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "[AFTER]bureaucrat3's grade: " <<  bureaucrat3.getGrade() << std::endl;
}

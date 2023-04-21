#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	Bureaucrat bureaucrat1("b1", 130);
	Bureaucrat bureaucrat2("b2", 40);
	Bureaucrat bureaucrat3("b3", 2);

	Intern  intern;
	AForm* shrubbery;
	AForm* robotomy;
	AForm* pardon;

	shrubbery = intern.makeForm("shrubbery creation", "Home"); // 145, 137
	robotomy = intern.makeForm("robotomy request", "Factory"); // 72, 45
	pardon = intern.makeForm("presidential pardon", "Congress"); //25, 5

	std::cout << "\n1: " << std::endl;
	try {
		bureaucrat1.executeForm(*shrubbery);
		bureaucrat1.signForm(*shrubbery);
		bureaucrat1.executeForm(*shrubbery);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n2: " << std::endl;
	try {
		bureaucrat2.executeForm(*robotomy);
		bureaucrat2.signForm(*robotomy);
		bureaucrat2.executeForm(*robotomy);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n3: " << std::endl;
	try {
		bureaucrat3.executeForm(*pardon);
		bureaucrat3.signForm(*pardon);
		bureaucrat3.executeForm(*pardon);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n==========CHECK FORM TARGET==========" << std::endl;
	std::cout << ((ShrubberyCreationForm *)shrubbery)->getTarget() << std::endl;
	std::cout << ((RobotomyRequestForm *)robotomy)->getTarget() << std::endl;
	std::cout << ((PresidentialPardonForm *)pardon)->getTarget() << std::endl;

	delete shrubbery;
	delete robotomy;
	delete pardon;
}

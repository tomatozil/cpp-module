#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	Bureaucrat bureaucrat1("b1", 140);
	Bureaucrat bureaucrat2("b2", 40);
	Bureaucrat bureaucrat3("b3", 2);

	ShrubberyCreationForm shrubbery("Home"); // 145, 137
	RobotomyRequestForm robotomy("Factory"); // 72, 45
	PresidentialPardonForm pardon("Congress"); //25, 5

	std::cout << "1: " << std::endl;
	try {
		bureaucrat1.executeForm(shrubbery);
		bureaucrat1.signForm(shrubbery);
		bureaucrat1.executeForm(shrubbery);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n2: " << std::endl;
	try {
		bureaucrat2.executeForm(robotomy);
		bureaucrat2.signForm(robotomy);
		bureaucrat2.executeForm(robotomy);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n3: " << std::endl;
	try {
		bureaucrat3.executeForm(pardon);
		bureaucrat3.signForm(pardon);
		bureaucrat3.executeForm(pardon);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
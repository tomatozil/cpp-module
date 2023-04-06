#include "Bureaucra.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	Bureaucra bureaucra1("b1", 130);
	Bureaucra bureaucra2("b2", 40);
	Bureaucra bureaucra3("b3", 2);

	ShrubberyCreationForm shrubbery("Home"); // 145, 137
	RobotomyRequestForm robotomy("Factory"); // 72, 45
	PresidentialPardonForm pardon("Congress"); //25, 5

	std::cout << "1: " << std::endl;
	try {
		bureaucra1.executeForm(shrubbery);
		bureaucra1.signForm(shrubbery);
		bureaucra1.executeForm(shrubbery);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n2: " << std::endl;
	try {
		bureaucra2.executeForm(robotomy);
		bureaucra2.signForm(robotomy);
		bureaucra2.executeForm(robotomy);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n3: " << std::endl;
	try {
		bureaucra3.executeForm(pardon);
		bureaucra3.signForm(pardon);
		bureaucra3.executeForm(pardon);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
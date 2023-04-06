#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

AForm* Intern::makeForm(const std::string &formName, const std::string &formTarget) {
	std::string formList[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	for (int i = 0; i < 3; i++) {
		if (formName == formList[i]) {
			std::cout << "Intern creates " << formName << " form" << std::endl;
			switch (i) {
				case 0:
					return new ShrubberyCreationForm(formTarget);
				case 1:
					return new RobotomyRequestForm(formTarget);
				case 2:
					return new PresidentialPardonForm(formTarget);
			}
		}
	}
	std::cout << formName << " doesn’t exist." << std::endl;
	return (0);
}

Intern::Intern() {}
Intern::~Intern() {}


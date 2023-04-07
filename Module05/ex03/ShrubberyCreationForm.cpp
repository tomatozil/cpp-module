#include "ShrubberyCreationForm.hpp"

void ShrubberyCreationForm::execute(Bureaucra const & executor) const throw(NotSignedYetException, GradeTooLowException) {
	if (this->getSignedStatus() == false)
		throw NotSignedYetException();
	if (executor.getGrade() > this->getExeGrade())
		throw GradeTooLowException();
	std::cout << executor.getName() << " executed " << this->getName() << std::endl;
	std::ofstream tree(target + "_shrubbery");
	if (tree.is_open()) {
		tree <<  "       _-_\n"
				 "    /~~   ~~\\\n"
				 " /~~         ~~\\\n"
				 "{               }\n"
				 " \\  _-     -_  /\n"
				 "   ~  \\\\ //  ~\n"
				 "_- -   | | _- _\n"
				 "  _ -  | |   -_\n"
				 "      // \\\\\n";
		tree.close();
	}
}

std::string ShrubberyCreationForm::getTarget() const {
	return (target);
}

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("defalt", 145, 137), target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137) , target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &origin)
	: AForm(origin.getName(), origin.getSignGrade(), origin.getExeGrade()), target(origin.target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &shrubberyCreation) {
	(void)shrubberyCreation;
	return (*this); // nothing can't be initialized with assignment target
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

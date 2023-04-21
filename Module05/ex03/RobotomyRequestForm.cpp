#include "RobotomyRequestForm.hpp"

void RobotomyRequestForm::execute(Bureaucrat const & executor) const throw(NotSignedYetException, GradeTooLowException) {
	if (this->getSignedStatus() == false)
		throw NotSignedYetException();
	if (executor.getGrade() > this->getExeGrade())
		throw GradeTooLowException();
	std::cout << executor.getName() << " executed " << this->getName() << std::endl;
	std::cout << "drilling .. drilling .. drilling" << std::endl;
	srand(time(0));
	if (rand() % 2 == 1)
		std::cout << "Robotomized fail." << std::endl;
	else
		std::cout << target << " has been robotomized successfully 50% of the time." << std::endl;
}

std::string RobotomyRequestForm::getTarget() const {
	return (target);
}

RobotomyRequestForm::RobotomyRequestForm() : AForm("default", 72, 45), target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
		: AForm("RobotomyRequestForm", 72, 45) , target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &origin)
		: AForm(origin.getName(), origin.getSignGrade(), origin.getExeGrade()) , target(origin.target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& robotomyRequest) {
	(void)robotomyRequest;
	return (*this); // nothing can't be initialized with assignment target
}

RobotomyRequestForm::~RobotomyRequestForm() {}


#include "PresidentialPardonForm.hpp"

void PresidentialPardonForm::execute(Bureaucra const & executor) const throw(NotSignedYetException, GradeTooLowException) {
	if (this->getSignedStatus() == false)
		throw NotSignedYetException();
	if (executor.getGrade() > this->getExeGrade())
		throw GradeTooLowException();
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::string PresidentialPardonForm::getTarget() const {
	return (target);
}

PresidentialPardonForm::PresidentialPardonForm() : AForm("default", 25, 5) , target("default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
		: AForm("PresidentialPardonForm", 25, 5) , target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &origin)
		: AForm(origin.getName(), origin.getSignGrade(), origin.getExeGrade()) , target(origin.target) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& presidentialPardon) {
	(void)presidentialPardon;
	return (*this); // nothing can't be initialized with assignment target
}

PresidentialPardonForm::~PresidentialPardonForm() {}



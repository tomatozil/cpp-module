#include "AForm.hpp"

std::string AForm::getName() const {
	return (name);
}

bool AForm::getSignedStatus() const {
	return (isSigned);
}

unsigned int AForm::getSignGrade() const {
	return (signGrade);
}

unsigned int AForm::getExeGrade() const {
	return (exeGrade);
}

void AForm::beSigned(Bureaucrat &bureaucrat) throw(GradeTooLowException) {
	if (bureaucrat.getGrade() >this->getSignGrade() )
		throw AForm::GradeTooLowException();
	std::cout << bureaucrat.getName() << " just signed." << std::endl;
	this->isSigned = true;
}

AForm::AForm() : name("default"), isSigned(false), signGrade(150), exeGrade(150) {}

AForm::AForm(const std::string &name, const unsigned int signGrade, const unsigned int exeGrade)
	:name(name), isSigned(false), signGrade(signGrade), exeGrade(exeGrade) {
	isSigned = false;
	if (signGrade < 1 || exeGrade < 1)
		throw AForm::InitialGradeTooHighException();
	if (signGrade > 150 ||  exeGrade > 150)
		throw AForm::InitialGradeTooLowException();
}

AForm::AForm(const AForm &origin) : name(origin.name), isSigned(origin.isSigned), signGrade(origin.signGrade), exeGrade(origin.exeGrade) {}

AForm& AForm::operator=(const AForm &form) {
	if (this == &form)
		return (*this);
	isSigned = form.isSigned;
	return (*this);
}

AForm::~AForm() {}

const char * AForm::GradeTooHighException::what() const throw() {
	return ("At Form: Grade is too high.");
}

const char * AForm::GradeTooLowException::what() const throw() {
	return ("At Form: Grade is too high.");
}

const char * AForm::InitialGradeTooHighException::what() const throw() {
	return ("At Form: Grade trying to initialize is too high.");
}

const char * AForm::InitialGradeTooLowException::what() const throw() {
	return ("At Form: Grade trying to initialize is too low.");
}

const char * AForm::NotSignedYetException::what() const throw() {
	return ("At Form: Impossible to execute, Cause is not signed yet.");
}

std::ostream& operator<<(std::ostream& out, const AForm& form) {
	out << "\n=====Form's info====="
		<< "\nname: " << form.getName()
		<< "\nsign status: " << form.getSignedStatus()
		<< "\nsignable grade: " << form.getSignGrade()
		<< "\nexecutable grade: " << form.getExeGrade() << std::endl;
	return (out);
}
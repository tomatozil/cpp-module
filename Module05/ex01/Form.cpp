#include "Form.hpp"

std::string Form::getName() const {
	return (name);
}

bool Form::getSignedStatus() const {
	return (isSigned);
}

unsigned int Form::getSignGrade() const {
	return (signGrade);
}

unsigned int Form::getExeGrade() const {
	return (exeGrade);
}

void Form::beSigned(Bureaucrat &bureaucrat) throw(Form::GradeTooLowException) {
	if (bureaucratt.getGrade() > this->getSignGrade())
		throw Form::GradeTooLowException();
	std::cout << bureaucrat.getName() << " just signed." << std::endl;
	this->isSigned = true;
}

Form::Form() : name("default"), isSigned(false), signGrade(150), exeGrade(150) {}

Form::Form(const std::string &name, const unsigned int signGrade, const unsigned int exeGrade)
	:name(name), isSigned(false), signGrade(signGrade), exeGrade(exeGrade) {
	if (signGrade < 1 || exeGrade < 1)
		throw InitialGradeTooHighException();
	if (signGrade > 150 ||  exeGrade > 150)
		throw InitialGradeTooLowException();
}

Form::Form(const Form &origin) : name(origin.name), isSigned(origin.isSigned), signGrade(origin.signGrade), exeGrade(origin.exeGrade) {}

Form& Form::operator=(const Form &form) {
	if (this == &form)
		return (*this);
	isSigned = form.isSigned;
	return (*this);
}

Form::~Form() {}

const char * Form::GradeTooHighException::what() const throw() {
	return ("At Form: Grade is too high.");
}

const char * Form::GradeTooLowException::what() const throw() {
	return ("At Form: Grade is too high.");
}

const char* Form::InitialGradeTooHighException::what() const throw() {
	return ("At Form: Grade trying to initialize is too high.");
}

const char* Form::InitialGradeTooLowException::what() const throw() {
	return ("At Form: Grade trying to initialize is too low.");
}

std::ostream& operator<<(std::ostream& out, const Form& form) {
	out << "\n=====Form's info====="
		<< "\nname: " << form.getName()
		<< "\nsign status: " << form.getSignedStatus()
		<< "\nsignable grade: " << form.getSignGrade()
		<< "\nexecutable grade: " << form.getExeGrade() << std::endl;
	return (out);
}
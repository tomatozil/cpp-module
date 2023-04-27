#include "Bureaucrat.hpp"

std::string Bureaucrat::getName() const {
	return (name);
}

unsigned int Bureaucrat::getGrade() const {
	return (grade);
}

void Bureaucrat::incrementGrade() throw(GradeTooHighException) {
	if (grade == 1)
		throw GradeTooHighException();
	std::cout << "Grade has increased successfully." << std::endl;
	--grade;
}

void Bureaucrat::decrementGrade() throw(GradeTooLowException) {
	if (grade == 150)
		throw GradeTooLowException();
	std::cout << "Grade has lowered successfully." << std::endl;
	++grade;
}

void Bureaucrat::signForm(AForm& form) {
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	} catch (AForm::GradeTooLowException& e) {
		std::cout << this->getName() << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm &form) {
	try {
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	} catch (std::exception& e) {
		std::cout << this->getName() << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat() : name("Default"), grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, unsigned int grade) throw(InitialGradeTooHighException, InitialGradeTooLowException)
	: name(name), grade(grade) {
	if (grade < 1)
		throw InitialGradeTooHighException();
	if (grade > 150)
		throw InitialGradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& origin) : name(origin.name), grade(origin.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& bureaucrat) {
	if (this == &bureaucrat)
		return (*this);
	// const variable name can't be initialized
	grade = bureaucrat.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("At Bureaucrat: Grade is too high.");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("At Bureaucrat: Grade is too low.");
}

const char* Bureaucrat::InitialGradeTooHighException::what() const throw() {
	return ("At Bureaucrat: Grade trying to initialize is too high.");
}

const char* Bureaucrat::InitialGradeTooLowException::what() const throw() {
	return ("At Bureaucrat: Grade trying to initialize is too low.");
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat) {
	out << bureaucrat.getName() << ", bureaucratt grade " << bureaucrat.getGrade() << std::endl;
	return (out);
}


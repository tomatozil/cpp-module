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

Bureaucrat::Bureaucrat() : name("Default"), grade(150) {}

Bureaucrat::Bureaucrat(const std::string& name, unsigned int grade) throw(GradeTooHighException, GradeTooLowException): name(name), grade(grade) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& origin) : name(origin.name), grade(origin.grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& bureaucrat) {
	if (this == &bureaucrat)
		return (*this);
	// const variable name can't be changed
	grade = bureaucrat.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("WARNING: Grade is too high.");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("WARNING: Grade is too low.");
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat) {
	out << bureaucrat.getName() << ", bureaucratt grade " << bureaucrat.getGrade() << std::endl;
	return (out);
}


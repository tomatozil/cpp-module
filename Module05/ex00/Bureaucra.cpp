#include "Bureaucra.hpp"

std::string Bureaucra::getName() const {
	return (name);
}

unsigned int Bureaucra::getGrade() const {
	return (grade);
}

void Bureaucra::incrementGrade() throw(GradeTooHighException) {
	if (grade == 1)
		throw GradeTooHighException();
	std::cout << "Grade has increased successfully." << std::endl;
	--grade;
}

void Bureaucra::decrementGrade() throw(GradeTooLowException) {
	if (grade == 150)
		throw GradeTooLowException();
	std::cout << "Grade has lowered successfully." << std::endl;
	++grade;
}

Bureaucra::Bureaucra() : name("Default"), grade(150) {}

Bureaucra::Bureaucra(const std::string& name, unsigned int grade) : name(name), grade(grade) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
}

Bureaucra::Bureaucra(const Bureaucra& origin) : name(origin.name), grade(origin.grade) {}

Bureaucra& Bureaucra::operator=(const Bureaucra& bureaucra) {
	if (this == &bureaucra)
		return (*this);
	// const variable can't be initialized
	grade = bureaucra.grade;
	return (*this);
}

Bureaucra::~Bureaucra() {}

const char* Bureaucra::GradeTooHighException::what() const throw() {
	return ("WARNING: Grade is too high.");
}

const char* Bureaucra::GradeTooLowException::what() const throw() {
	return ("WARNING: Grade is too low.");
}

std::ostream& operator<<(std::ostream& out, const Bureaucra& bureaucra) {
	out << bureaucra.getName() << ", bureaucrat grade " << bureaucra.getGrade() << std::endl;
	return (out);
}


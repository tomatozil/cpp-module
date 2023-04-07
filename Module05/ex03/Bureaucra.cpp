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

void Bureaucra::signForm(AForm& form) {
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	} catch (AForm::GradeTooLowException& e) {
		std::cout << this->getName() << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucra::executeForm(const AForm &form) {
	try {
		form.execute(*this);
	} catch (std::exception& e) {
		std::cout << this->getName() << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

Bureaucra::Bureaucra() : name("Default"), grade(150) {}

Bureaucra::Bureaucra(const std::string& name, unsigned int grade) : name(name), grade(grade) {
	if (grade < 1)
		throw InitialGradeTooHighException();
	if (grade > 150)
		throw InitialGradeTooLowException();
}

Bureaucra::Bureaucra(const Bureaucra& origin) : name(origin.name), grade(origin.grade) {}

Bureaucra& Bureaucra::operator=(const Bureaucra& bureaucra) {
	if (this == &bureaucra)
		return (*this);
	// const variable name can't be initialized
	grade = bureaucra.grade;
	return (*this);
}

Bureaucra::~Bureaucra() {}

const char* Bureaucra::GradeTooHighException::what() const throw() {
	return ("At Bureaucra: Grade is too high.");
}

const char* Bureaucra::GradeTooLowException::what() const throw() {
	return ("At Bureaucra: Grade is too low.");
}

const char* Bureaucra::InitialGradeTooHighException::what() const throw() {
	return ("At Bureaucra: Grade trying to initialize is too high.");
}

const char* Bureaucra::InitialGradeTooLowException::what() const throw() {
	return ("At Bureaucra: Grade trying to initialize is too low.");
}

std::ostream& operator<<(std::ostream& out, const Bureaucra& bureaucra) {
	out << bureaucra.getName() << ", bureaucrat grade " << bureaucra.getGrade() << std::endl;
	return (out);
}


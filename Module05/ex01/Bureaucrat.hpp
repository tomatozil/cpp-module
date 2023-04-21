#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat {
public:
	std::string getName() const;
	unsigned int getGrade() const;
	void incrementGrade() throw(GradeTooHighException);
	void decrementGrade() throw(GradeTooLowException);
	void signForm(Form& form);

	Bureaucrat();
	Bureaucrat(const std::string& name, unsigned int grade);
	Bureaucrat(const Bureaucrat& origin);
	Bureaucrat& operator=(const Bureaucrat& bureaucrat);
	~Bureaucrat();

	class GradeTooHighException : public std::exception {
		const char * what() const throw();
	};

	class GradeTooLowException : public std::exception {
		const char * what() const throw();
	};

	class InitialGradeTooHighException : public std::exception {
		const char * what() const throw();
	};

	class InitialGradeTooLowException : public std::exception {
		const char * what() const throw();
	};

private:
	const std::string name;
	unsigned int grade;
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif

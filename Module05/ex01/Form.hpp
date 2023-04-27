#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
public:
	std::string getName() const;
	bool getSignedStatus() const;
	unsigned int getSignGrade() const;
	unsigned int getExeGrade() const;

	void beSigned(Bureaucrat& bureaucrat) throw(GradeTooLowException); //changed the status to signed

	Form();
	Form(const std::string& name, const unsigned int signGrade, const unsigned int exeGrade) throw(InitialGradeTooHighException, InitialGradeTooLowException);
	Form(const Form& origin);
	Form& operator=(const Form& form);
	~Form();

	class GradeTooHighException : public std::exception {
	public:
		const char * what() const throw();
	};

	class GradeTooLowException : public std::exception {
	public:
		const char * what() const throw();
	};

	class InitialGradeTooHighException : public std::exception {
	public:
		const char * what() const throw();
	};

	class InitialGradeTooLowException : public std::exception {
	public:
		const char * what() const throw();
	};

private:
	const std::string name;
	bool isSigned; //defualt = 0;
	const unsigned int signGrade;
	const unsigned int exeGrade;
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif

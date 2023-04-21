#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
public:
	std::string getName() const;
	bool getSignedStatus() const;
	unsigned int getSignGrade() const;
	unsigned int getExeGrade() const;

	void beSigned(Bureaucrat& bureaucrat) throw(GradeTooLowException); //changed the status to signed
	virtual void execute(Bureaucrat const & executor) const throw(NotSignedYetException, GradeTooLowException) = 0;

	AForm();
	AForm(const std::string& name, const unsigned int signGrade, const unsigned int exeGrade);
	AForm(const AForm& origin);
	AForm& operator=(const AForm& form);
	virtual ~AForm();

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

	class NotSignedYetException : public std::exception {
	public:
		const char * what() const throw();
	};

private:
	const std::string name;
	bool isSigned; //defualt = 0;
	const unsigned int signGrade;
	const unsigned int exeGrade;
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif

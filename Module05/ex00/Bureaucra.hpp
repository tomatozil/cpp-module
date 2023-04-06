#ifndef BUREAUCRA_HPP
#define BUREAUCRA_HPP

#include <iostream>

class Bureaucra {
public:
	std::string getName() const;
	unsigned int getGrade() const;
	void incrementGrade() throw(GradeTooHighException);
	void decrementGrade() throw(GradeTooLowException);

	Bureaucra();
	Bureaucra(const std::string& name, unsigned int grade);
	Bureaucra(const Bureaucra& origin);
	Bureaucra& operator=(const Bureaucra& bureaucra);
	~Bureaucra();

	class GradeTooHighException : public std::exception {
		const char * what() const throw();
	};

	class GradeTooLowException : public std::exception {
		const char * what() const throw();
	};

private:
	const std::string name;
	unsigned int grade;
};

std::ostream& operator<<(std::ostream& out, const Bureaucra& bureaucra);

#endif

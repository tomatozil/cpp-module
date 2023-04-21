#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
public:
	virtual void execute(Bureaucrat const & executor) const throw(NotSignedYetException, GradeTooLowException);

	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& origin);
	virtual ~ShrubberyCreationForm();

private:
	const std::string target;
	ShrubberyCreationForm();
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& shrubberyCreation);
};

#endif

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
public:
	virtual void execute(Bureaucra const & executor) const throw(NotSignedYetException, GradeTooLowException);
	std::string getTarget() const;

	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& origin);
	virtual ~ShrubberyCreationForm();

private:
	const std::string target;
	ShrubberyCreationForm();
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& shrubberyCreation);
};

#endif

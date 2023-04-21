#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
public:
	virtual void execute(Bureaucrat const & executor) const throw(NotSignedYetException, GradeTooLowException);
	std::string getTarget() const;

	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& origin);
	virtual ~PresidentialPardonForm();

private:
	const std::string target;
	PresidentialPardonForm();
	PresidentialPardonForm& operator=(const PresidentialPardonForm& presidentialPardon);
};

#endif

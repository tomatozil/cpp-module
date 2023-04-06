#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <cstdlib>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
public:
	virtual void execute(Bureaucra const & executor) const throw(NotSignedYetException, GradeTooLowException);
	std::string getTarget() const;

	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& origin);
	virtual ~RobotomyRequestForm();

private:
	const std::string target;
	RobotomyRequestForm();
	RobotomyRequestForm& operator=(const RobotomyRequestForm& robotomyRequest);
};

#endif

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class Intern {
public:
	AForm* makeForm(const std::string& formName, const std::string& formTarget);

	Intern();
	~Intern();

private:
	Intern(const Intern& origin);
	Intern& operator=(const Intern& intern);
};

#endif

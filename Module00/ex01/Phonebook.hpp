#ifndef PHONEBOOK_H_
# define PHONEBOOK_H_

# include "Contact.hpp"
# include <iomanip>

class Phonebook {
	Contact contact[8];
	int index;

public:
	void AddContact();
	void PrintPhonebook();
	void Search();
	std::string CutTen(std::string);
	Phonebook();
	~Phonebook();
};

#endif

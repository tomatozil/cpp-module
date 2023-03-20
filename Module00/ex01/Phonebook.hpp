#ifndef PHONEBOOK_H_
# define PHONEBOOK_H_

# include "Contact.hpp"
# include <iomanip>

class Phonebook {
public:
	void AddContact();
	void PrintPhonebook();
	void Search();
	std::string CutTen(std::string);
	Phonebook();
	~Phonebook();

private:
	Contact contact[8];
	int index;
};

#endif

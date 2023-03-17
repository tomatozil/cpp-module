#include "Phonebook.hpp"

int main() {
	std::string type;
	Phonebook phonebook;

	while (!std::cin.eof()) {
		std::cout << "Enter one of these three: ADD, SEARCH, EXIT" << std::endl;
		std::getline(std::cin, type);
		if (type == "EXIT")
			break ;
		else if (type == "ADD")
			phonebook.AddContact();
		else if (type == "SEARCH")
			phonebook.Search();
	}
	return 0;
}
#include "Harl.hpp"

int main() {
	Harl harl;
	std::string level;

	std::cout << "Enter one of these 4 complaint DEBUG, INFO, WARNING, ERROR\n"
				 << "or DONE if you want to end" << std::endl;
	while (getline(std::cin, level)) {
		if (level == "DONE")
			break ;
		harl.complain(level);
		std::cout << "\nEnter one of these 4 complaint DEBUG, INFO, WARNING, ERROR\n"
				  << "or DONE if you want to end" << std::endl;
	}
	return (0);
}

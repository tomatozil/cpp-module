#include "Harl.hpp"

int main() {
	Harl harl;
	std::string level;

	std::cout << "Enter one of these 4 complaint DEBUG, INFO, WARNING, ERROR\n"
				 << "or DONE if you want to end" << std::endl;
	getline(std::cin, level);
	harl.complain(level);
	return (0);
}

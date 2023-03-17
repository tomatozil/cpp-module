#include <iostream>

void to_uppercase(char *string){
	std::string str(string);
	for(std::string::iterator i = str.begin(); i < str.end(); i++)
		std::cout << (char)std::toupper(*i);
}

int main(int ac, char *av[]) {
	if (ac == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for(int i = 1; i < ac; i++)
		to_uppercase(av[i]);
	std::cout << std::endl;
	return 0;
}

#include "Replace.hpp"

int main(int ac, char *av[]) {
	if (ac != 4) {
		std::cerr << "Error: you need to enter 4 argument(EXEC FILE, FILEPATH, STR1[to be replaced], STR2[replacement])\n";
		return (1);
	}
	if (!*av[1]) {
		std::cerr << "Error: filepath is empty\n";
		return (1);
	}
	if (!*av[2] || !*av[3]) {
		std::cerr << "Error: string is empty\n";
		return (1);
	}
	Replace replace(av[1], av[2], av[3]);
	if (!replace.execute())
		return (1);
	return (0);
}
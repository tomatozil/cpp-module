#include "BitCoinChange.hpp"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cout << "Error: could not open file." << std::endl;
		return -1;
	}
	std::string filePath(argv[1]);
	if (BitCoinChange::getExtension(filePath) != ".txt") {
		std::cout << "Error: did not receive txt file." << std::endl;
		return -1;
	}
	std::ifstream infile(filePath);
	if (!infile.is_open()) {
		std::cout << "Error: file open fail." << std::endl;
		return -1;
	}
	try {
		BitCoinChange bitCoinChange;
		std::string line;
		std::getline(infile, line);
		while (std::getline(infile, line)) {
			std::pair<std::string, float> pair = bitCoinChange.txtToPair(line);
			if (pair.first.find("Error") != std::string::npos)
				std::cout << pair.first << std::endl;
			else {
				float coinValue = pair.second;
				float coinPrice = bitCoinChange.closestValue(pair.first);
				if (coinPrice == -0.1f)
					std::cout << "Error: out of range." << std::endl;
				else
					std::cout << pair.first << "=> " << coinValue << " = " << coinPrice * coinValue << std::endl;
			}
		}
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
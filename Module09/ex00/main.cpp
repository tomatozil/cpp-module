#include "BitCoinChange.hpp"
#include <fstream>
#include <sstream>

//int main(int argc, char *argv[]) {
//	// .txt 파일 유효성
//	if (argc != 2) {
//		std::cout << "Error: could not open file." << std::endl;
//		return -1;
//	}
//	// .csv -> std::map database, .txt -> std::map inputfile
//	try {
//		std::string filName(argv[1]);
//		BitCoinChange::transDataInMap(filName);
//	} catch (std::exception& e) {
//		std::cout << e.what() << std::endl;
//	}
//	// inputfile의 key와 같거나 작은 database key를 찾고, value끼리 곱하기
//}

int main() {
	std::ifstream stream("../ex00/tmp.csv");
	if (!stream.is_open()) {
		return -1;
	}
	std::string line;
	std::getline(stream, line);
	while (std::getline(stream, line)) {
		std::cout << "\noriginal line: " << line << "\n";
		std::cout << "after ',': " << line.substr(0, line.find(',')) << "\n";
		std::stringstream insstream(line.substr(line.find(',') + 1));
		float fvalue;
		insstream >> fvalue;
		std::cout << std::fixed << std::setprecision(2) << fvalue << std::endl;
		insstream.clear();

		insstream.str(line.substr(line.find(',') + 1));
		int ivalue;
		insstream >> ivalue;
		std::cout << ivalue << std::endl;
	}
}
#include "BitCoinChange.hpp"

int main(int argc, char *argv[]) {
	// .txt 파일 유효성
	if (argc != 2) {
		std::cout << "Error: could not open file." << std::endl;
		return -1;
	}
	// .csv -> std::map database, .txt -> std::map inputfile
	try {
		std::string filePath(argv[1]);
		if (BitCoinChange::getExtension(filePath) != ".txt") {
			std::cout << "Error: did not receive txt file." << std::endl;
			return -1;
		}
		BitCoinChange bitCoinChange;

	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	// inputfile의 key와 같거나 작은 database key를 찾고, value끼리 곱하기
}


//class A {
//public:
//	void csvInMap(std::string &filePath) {
//		std::ifstream infile(filePath);
//		if (!infile.is_open()) {
//			throw std::runtime_error("Error: file open fail.");
//		}
//		std::string line;
//		std::getline(infile, line);
//		while (std::getline(infile, line)) {
//			std::string key;
//			float value;
//			size_t commPos = line.find(','); //형식이 , 가 아니면
//			if (commPos == std::string::npos)
//				throw std::runtime_error("Error: could not interpret file.");
//			//date(Year-Month-Day)
//			key = line.substr(0, commPos);
//			//price
//			std::string price = line.substr(commPos + 1);
//			std::stringstream insstream(price);
//			size_t dotPos = price.find('.');
//			if (dotPos == std::string::npos)
//				insstream >> std::fixed >> std::setprecision(0) >> value;
//			else
//				insstream >> std::fixed >> std::setprecision(price.length() - dotPos - (size_t)1) >> value;
//			dataBase[key] = value;
//		}
//		infile.close();
//	}
//
//	void txtInMap(std::string& filePath) {
//		std::ifstream infile(filePath);
//		if (!infile.is_open()) {
//			throw std::runtime_error("Error: file open fail.");
//		}
//		std::string line;
//		std::getline(infile, line);
//		while (std::getline(infile, line)) {
//			std::string key;
//			float value;
//			size_t barPos = line.find('|'); //형식이 , 가 아니면
//			if (barPos == std::string::npos) {
//				key = "Error: bad input => " + line.substr(0, barPos);
//				inputFile.insert(std::make_pair(key, -1.0f));
//			}
//			else {
//				key = line.substr(0, barPos);
//				std::string price = line.substr(barPos + 1);
//				std::stringstream insstream(price);
//				size_t dotPos = price.find('.');
//				if (dotPos == std::string::npos)
//					insstream >> std::fixed >> std::setprecision(0) >> value;
//				else
//					insstream >> std::fixed >> std::setprecision(price.length() - dotPos - 1) >> value;
//
//				if (value < 0)
//					key = "Error: not a positive number.";
//				if (value > 1000) {
//					key = "Error: too large a number.";
//				}
//				inputFile.insert(std::make_pair(key, value));
//			}
//		}
//		infile.close();
//	}
//
//	void printMap() {
//		std::map<std::string, float>::iterator iterator;
//
//		for(iterator = dataBase.begin(); iterator != dataBase.end(); ++iterator) {
//			if (iterator->first.find("Error") != std::string::npos)
//				std::cout << iterator->first.substr(iterator->first.find("Error")) << std::endl;
//			else {
//				std::cout << iterator->first << " => " << iterator->second << std::endl;
//			}
//		}
//	}
//
//	size_t getMapSize() {
//		return inputFile.size();
//	}
//private:
//	std::map<std::string, float> dataBase;
//	std::multimap<std::string, float> inputFile;
//};
//
//int main() {
//	A a;
////	std::string txtPath("../input.txt");
//	std::string csvPath("../ex00/tmp.csv");
//	a.csvInMap(csvPath);
////	a.txtInMap(txtPath);
//	a.printMap();
//}
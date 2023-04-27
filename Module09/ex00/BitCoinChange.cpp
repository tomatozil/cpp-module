#include "BitCoinChange.hpp"
#include <fstream>
#include <sstream>

std::string getExtension(std::string& fileName) {
	size_t dotPos = fileName.find('.');
	if (dotPos == std::string::npos)
		return NULL;
	return fileName.substr(dotPos);
}

void BitCoinChange::transDataInMap(std::string& fileName) {
	if (getExtension(fileName) != ".txt")
		throw std::invalid_argument("Error: incorrect file extension.");
	std::ifstream infile("../ex00/data.csv");
	if (!infile.is_open()) {
		throw FileOpenFailureException();
	}
	std::string line;
	std::getline(infile, line);
	while (std::getline(infile, line)) {
		//date(Year-Month-Day)
		std::string key = line.substr(0, line.find(','));
		//price
		std::stringstream insstream(line.substr(line.find(',') + 1));
		float value;
		insstream >> value;
		inputFile[key] = value; // 중복은 >?!
	}
	infile.close();
}

BitCoinChange::BitCoinChange() {}

BitCoinChange::BitCoinChange(const BitCoinChange &origin)
//	: dataBase(origin.dataBase), inputFile(origin.inputFile)
	{}

BitCoinChange& BitCoinChange::operator=(const BitCoinChange &bitCoinChange) {
//	if (this == &bitCoinChange)
//		return (*this);
//	if (this->dataBase != bitCoinChange.dataBase) {
//		this->dataBase = bitCoinChange.dataBase;
//	}
//	if (this->inputFile != bitCoinChange.inputFile) {
//		this->inputFile = bitCoinChange.inputFile;
//	}
	return (*this);
}

BitCoinChange::~BitCoinChange() {}

const char *BitCoinChange::FileOpenFailureException::what() const throw() {
	return "Error: file open fail.";
}
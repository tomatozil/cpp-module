#include "BitCoinChange.hpp"
#include <fstream>
#include <sstream>

std::string BitCoinChange::getExtension(std::string& filePath) {
	size_t dotPos = filePath.rfind('.');
	if (dotPos == std::string::npos)
		return "";
	return filePath.substr(dotPos);
}

void BitCoinChange::csvInMap(std::string &filePath) {
	std::ifstream infile(filePath);
	if (!infile.is_open()) {
		throw std::runtime_error("Error: file open fail.");
	}
	std::string line;
	std::getline(infile, line);
	while (std::getline(infile, line)) {
		std::string key;
		float value;
		size_t commPos = line.find(','); //형식이 , 가 아니면
		if (commPos == std::string::npos)
			throw std::runtime_error("Error: could not interpret file.");
		//date(Year-Month-Day)
		key = line.substr(0, commPos);
		//price
		std::string price = line.substr(commPos + 1);
		std::stringstream insstream(price);
		size_t dotPos = price.find('.');
		if (dotPos == std::string::npos)
			insstream >> std::fixed >> std::setprecision(0) >> value;
		else
			insstream >> std::fixed >> std::setprecision(price.length() - dotPos - 1) >> value;
		dataBase[key] = value;
	}
	infile.close();
}

//void BitCoinChange::txtInMap(std::string& filePath) {
//	std::ifstream infile(filePath);
//	if (!infile.is_open()) {
//		throw std::runtime_error("Error: file open fail.");
//	}
//	std::string line;
//	std::getline(infile, line);
//	while (std::getline(infile, line)) {
//		std::string key;
//		float value;
//		size_t barPos = line.find('|'); //형식이 , 가 아니면
//		if (barPos == std::string::npos) {
//			key = "Error: bad input => " + line.substr(0, barPos);
//			inputFile.insert(std::make_pair(key, -1.0f));
//		}
//		else {
//			key = line.substr(0, barPos);
//			std::string price = line.substr(barPos + 1);
//			std::stringstream insstream(price);
//			size_t dotPos = price.find('.');
//			if (dotPos == std::string::npos)
//				insstream >> std::fixed >> std::setprecision(0) >> value;
//			else
//				insstream >> std::fixed >> std::setprecision(price.length() - dotPos - 1) >> value;
//
//			if (value < 0)
//				key = "Error: not a positive number.";
//			if (value > 1000)
//				key = "Error: too large a number.";
//			inputFile.insert(std::make_pair(key, value));
//		}
//	}
//	infile.close();
//}

//std::string BitCoinChange::transDataInMap(std::string& filePath) {
//	std::string extension = getExtension(filePath);
//	if (extension == ".txt")
//		txtInMap(filePath);
//	if (getExtension(filePath) == ".csv")
//		csvInMap(filePath);
//	return (extension);
//}

BitCoinChange::BitCoinChange() {
	std::string filePath("../ex00/data.csv");
	if (getExtension(filePath) != ".csv")
		throw std::runtime_error("Error: did not receive csv file.");
	csvInMap(filePath);
}

BitCoinChange::BitCoinChange(const BitCoinChange &origin)
	: dataBase(origin.dataBase) {}

BitCoinChange& BitCoinChange::operator=(const BitCoinChange &bitCoinChange) {
	if (this == &bitCoinChange)
		return (*this);
	if (this->dataBase != bitCoinChange.dataBase) {
		this->dataBase = bitCoinChange.dataBase;
	}
	return (*this);
}

BitCoinChange::~BitCoinChange() {}
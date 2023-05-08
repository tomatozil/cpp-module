#include "BitCoinChange.hpp"
#include <fstream>
#include <sstream>

std::string BitCoinChange::getExtension(std::string& filePath) {
	size_t dotPos = filePath.rfind('.');
	if (dotPos == std::string::npos)
		return "";
	return filePath.substr(dotPos);
}

void BitCoinChange::csvToMap(std::string &fileName) {
	std::ifstream infile(fileName);
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

std::pair<std::string, float> BitCoinChange::txtToPair(std::string& line) {
		std::string key;
		float value;
		size_t barPos = line.find('|'); //형식이 , 가 아니면
		if (barPos == std::string::npos) {
			key = "Error: bad input => " + line.substr(0, barPos);
			return std::make_pair(key, -1.0f);
		}
		else {
			key = line.substr(0, barPos);
			std::string price = line.substr(barPos + 1);
			std::stringstream insstream(price);
			size_t dotPos = price.find('.');
			if (dotPos == std::string::npos)
				insstream >> std::fixed >> std::setprecision(0) >> value;
			else
				insstream >> std::fixed >> std::setprecision(price.length() - dotPos - 1) >> value;
			if (value < 0)
				key = "Error: not a positive number.";
			if (value > 1000)
				key = "Error: too large a number.";
			return std::make_pair(key, value);
		}
}

float BitCoinChange::closestValue(std::string &targetKey) {
	std::map<std::string, float>::const_iterator iter;
	iter = dataBase.lower_bound(targetKey); // 끝에 " " 하나가 더 들어가서 항상 하나 뒤에 것이 나옴.
	if (iter == dataBase.end())
//		throw std::out_of_range("Error: out of range.");
		return -0.1f;
	iter--;
	if (iter->first.empty())
//		throw std::out_of_range("Error: out of range.");
		return -0.1f;
	return (iter->second);
}

BitCoinChange::BitCoinChange() {
	std::string filePath("data.csv");
	if (getExtension(filePath) != ".csv")
		throw std::runtime_error("Error: did not receive csv file.");
	csvToMap(filePath);
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

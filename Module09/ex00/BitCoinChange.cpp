#include "BitCoinChange.hpp"
#include <fstream>
#include <sstream>
#include <valarray>

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
		key = line.substr(0, commPos);
		std::string price = line.substr(commPos + 1);
		std::stringstream insstream(price);
		insstream >> value;
//		size_t dotPos = price.find('.');
//		if (dotPos == std::string::npos)
//			insstream >> std::fixed >> std::setprecision(0) >> value;
//		else
//			insstream >> std::fixed >> std::setprecision(price.length() - dotPos - 1) >> value;
		dataBase[key] = value;
	}
	infile.close();
}

int BitCoinChange::checkDate(std::string date) {
	size_t dash1Pos = date.find('-');
	if (dash1Pos == std::string::npos)
		return -1;
	std::string year = date.substr(0, dash1Pos);
	size_t dash2Pos = date.find('-', dash1Pos + 1);
	if (dash2Pos == std::string::npos)
		return -1;
	std::string month = date.substr(dash1Pos + 1, dash2Pos - dash1Pos - 1);
	std::string day = date.substr(dash2Pos + 1);

	std::istringstream yearStream(year);
	int yearValue;
	yearStream >> yearValue;
	if (yearStream.fail() || yearValue < 1900 || yearValue > 3000)
		return -1;

	std::istringstream monthStream(month);
	int monthValue;
	monthStream >> monthValue;
	if (monthStream.fail() || monthValue < 1 || monthValue > 12)
		return -1;

	std::istringstream dayStream(day);
	int dayValue;
	dayStream >> dayValue;
	if (dayStream.fail() || dayValue < 1 || dayValue > 31)
		return -1;
	return 1;
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
			if (checkDate(key) == -1)
				key = "Error: invalid date format.";
			std::string price = line.substr(barPos + 1);
			std::stringstream insstream(price);
			insstream >> value;
//			size_t dotPos = price.find('.');
//			if (dotPos == std::string::npos)
//				insstream >> std::fixed >> std::setprecision(0) >> value;
//			else
//				insstream >> std::fixed >> std::setprecision(price.length() - dotPos - 1) >> value;
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
	if (iter == dataBase.end()) {
		iter--;
		if (iter->first == targetKey.substr(0, 10))
			return (iter->second);
		else
			return -0.1f;
	}
	iter--;
	if (iter->first.empty())
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

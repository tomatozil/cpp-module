#ifndef MODULE09_BITCOINCHANGE_HPP
#define MODULE09_BITCOINCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

class BitCoinChange {
public:
	static std::string getExtension(std::string& filePath);
//	void txtInMap(std::string& filePath);
//	std::string transDataInMap(std::string& fileName);

	void multValues(float dataValue, float inputValue);

	BitCoinChange();
	~BitCoinChange();

private:
	void csvInMap(std::string& fileName);

	BitCoinChange(const BitCoinChange& origin);
	BitCoinChange& operator=(const BitCoinChange& bitCoinChange);

private:
	std::map<std::string, float> dataBase;
};
#endif

#ifndef MODULE09_BITCOINCHANGE_HPP
#define MODULE09_BITCOINCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

class BitCoinChange {
public:
	static std::string getExtension(std::string& filePath);
	std::pair<std::string, float> txtToPair(std::string& line);
	float closestValue(std::string& targetKey);

	BitCoinChange();
	~BitCoinChange();

private:
	void csvToMap(std::string& fileName);

	BitCoinChange(const BitCoinChange& origin);
	BitCoinChange& operator=(const BitCoinChange& bitCoinChange);

private:
	std::map<std::string, float> dataBase;
};
#endif

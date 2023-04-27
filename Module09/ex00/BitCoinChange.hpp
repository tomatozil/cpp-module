#ifndef MODULE09_BITCOINCHANGE_HPP
#define MODULE09_BITCOINCHANGE_HPP

#include <iostream>
#include <map>

class BitCoinChange {
public:
	void makeMap(std::string fileExtension);
	void multValues(float dataValue, float inputValue);

	BitCoinChange();
	BitCoinChange(const BitCoinChange& origin);
	BitCoinChange& operator=(const BitCoinChange& bitCoinChange);
	~BitCoinChange();
private:
	std::map<std::string, float> dataBase;
	std::map<std::string, float> inputFile;
};
#endif

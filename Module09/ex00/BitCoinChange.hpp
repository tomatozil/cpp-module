#ifndef MODULE09_BITCOINCHANGE_HPP
#define MODULE09_BITCOINCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>

class BitCoinChange {
public:
	static void transDataInMap(std::string& fileName);
	static void multValues(float dataValue, float inputValue);

private:
	BitCoinChange();
	BitCoinChange(const BitCoinChange& origin);
	BitCoinChange& operator=(const BitCoinChange& bitCoinChange);
	~BitCoinChange();

	class FileOpenFailureException : public std::exception {
		const char * what() const throw();
	};

	static std::map<std::string, float> dataBase;
	static std::map<std::string, float> inputFile;
};
#endif

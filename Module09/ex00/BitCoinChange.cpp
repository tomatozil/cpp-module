#include "BitCoinChange.hpp"

BitCoinChange::BitCoinChange() {}

BitCoinChange::BitCoinChange(const BitCoinChange &origin) : dataBase(origin.dataBase), inputFile(origin.inputFile) {
	this->dataBase.insert(origin.dataBase.begin(), origin.dataBase.end());
	this->inputFile.insert(origin.inputFile.begin(), origin.inputFile.end());
}

BitCoinChange& BitCoinChange::operator=(const BitCoinChange &bitCoinChange) {
	if (this == &bitCoinChange)
		return (*this);
	if (this->dataBase != bitCoinChange.dataBase)
		this->dataBase = bitCoinChange.dataBase;
		this->inputFile = bitCoinChange.inputFile;
		this->dataBase.insert(bitCoinChange.dataBase.begin(), bitCoinChange.dataBase.end());
		this->inputFile.insert(bitCoinChange.inputFile.begin(), bitCoinChange.inputFile.end());
	}
}

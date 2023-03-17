#include "Replace.hpp"

bool Replace::fileOpen(std::ifstream &readFile, std::ofstream &writeFile) {
	readFile.open(_file);
	if (!readFile.is_open()) {
		std::cerr << "Error: file open went wrong\n";
		return (false);
	}
	writeFile.open(_file + ".replace");
	if (!writeFile.is_open()) {
		std::cerr << "Error: file.replace open went wrong\n";
		return (false);
	}
	return (true);
}

bool Replace::execute() {
	std::ifstream readFile;
	std::ofstream writeFile;
	std::size_t cur;
	std::size_t idx;

	if (!fileOpen(readFile, writeFile))
		return (false);
	while (readFile) {
		std::string tmp;
		getline(readFile, tmp);
		if (!readFile.eof()) {
			tmp += "\n";
		}
		idx = 0;
		while (idx < tmp.length() && (cur = tmp.find(_before, idx)) != std::string::npos) {
			writeFile << tmp.substr(idx, cur - idx);
			writeFile << _after;
			idx = std::min(cur + _before.length(), tmp.length());
		}
		writeFile << tmp.substr(idx);
	}
	readFile.close();
	writeFile.close();
	return (true);
}

Replace::Replace(std::string file, std::string before, std::string after) : _file(file), _before(before), _after(after) {}

Replace::~Replace() {}
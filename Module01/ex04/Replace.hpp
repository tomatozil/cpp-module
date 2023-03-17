#ifndef REPLACE_H_
# define REPLACE_H_

# include <iostream>
# include <fstream>

class Replace {

public:
	bool execute();
	Replace(std::string file, std::string before, std::string after);
	~Replace();

private:
	const std::string _file;
	const std::string _before;
	const std::string _after;
	bool fileOpen(std::ifstream& readFile, std::ofstream& writeFile);
};

#endif

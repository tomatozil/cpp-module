#ifndef HARL_H_
# define HARL_H_

# include <iostream>

class Harl {

public:
	Harl();
	~Harl();
	void complain(std::string level);

private:
	void debug();
	void info();
	void warning();
	void error();
};

#endif

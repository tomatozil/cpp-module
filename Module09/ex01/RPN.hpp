#ifndef MODULE09_RPN_HPP
#define MODULE09_RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>

class RPN {
public:
	static bool isOperator(char c);
	static RPN* getInstance();
	ssize_t valuePoppedOut();
	void calc(char c);
	void pushPossibleValue(std::string::iterator& strIter);
	void checkStack();

private:
	RPN();
	RPN(const RPN& origin);
	RPN& operator=(const RPN& rpn);
	~RPN();

private:
	std::stack<ssize_t> stack;
	static RPN* instanceRPN;
};

#endif

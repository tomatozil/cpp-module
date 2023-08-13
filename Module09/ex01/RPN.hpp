#ifndef MODULE09_RPN_HPP
#define MODULE09_RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>

class RPN {
public:
	static bool isOperator(char c);
	ssize_t valuePoppedOut();
	void calc(char c);
	void pushPossibleValue(std::string::iterator& strIter);
	void checkStack();

	RPN();
	~RPN();
private:
	RPN(const RPN& origin);
	RPN& operator=(const RPN& rpn);

private:
	std::stack<ssize_t> stack;
};

#endif

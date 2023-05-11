#include "RPN.hpp"

ssize_t calcPlus(ssize_t first, ssize_t second) {
	return second + first;
}

ssize_t calcMinus(ssize_t first, ssize_t second) {
	return second - first;
}

ssize_t calcMult(ssize_t first, ssize_t second) {
	return second * first;
}

ssize_t calcDivide(ssize_t first, ssize_t second) {
	if (first == 0)
		throw std::runtime_error("Error");
	return second / first;
}

bool RPN::isOperator(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}

void RPN::pushPossibleValue(std::string::iterator& strIter) {
	if (*strIter == ' ')
		return ;
	if (isOperator(*strIter))
		return ;
	if (!isdigit(*strIter))
		throw std::runtime_error("Error");
	if (isdigit(*(strIter + 1)))
		throw std::runtime_error("Error");
	stack.push(*strIter - 48);
}

ssize_t RPN::valuePoppedOut() {
	if (stack.empty())
		throw std::runtime_error("Error: valance between number and operator sign doesn't good.");
	ssize_t i = stack.top();
	stack.pop();
	return i;
}

void RPN::calc(char c) {
	ssize_t ret;
	char operators[4] = {'+', '-', '*', '/'};
	int i = -1;
	while (++i < 4)
		if (c == operators[i])
			break;
	switch (i) {
		case 0:
			ret = calcPlus(valuePoppedOut(), valuePoppedOut());
			break;
		case 1:
			ret = calcMinus(valuePoppedOut(), valuePoppedOut());
			break;
		case 2:
			ret = calcMult(valuePoppedOut(), valuePoppedOut());
			break;
		case 3:
			ret = calcDivide(valuePoppedOut(), valuePoppedOut());
			break;
		default:
			throw std::runtime_error("Error: something wrong with calculation");
	}
	stack.push(ret);
}

void RPN::checkStack() {
	if (stack.size() != 1)
		throw std::runtime_error("Error: valance between number and operator sign doesn't good.");
	std::cout << stack.top() << std::endl;
}

RPN *RPN::getInstance() {
	if (instanceRPN == NULL)
		instanceRPN = new RPN();
	return (instanceRPN);
}

RPN::RPN() {}

RPN::~RPN() {
	delete instanceRPN;
}

RPN::RPN(const RPN &origin) {
	(void)origin;
	delete this;
}

//RPN &RPN::operator=(const RPN &rpn) {
//	delete this;
//}

#include "RPN.hpp"

size_t calcPlus(size_t first, size_t second) {
	return second + first;
}

size_t calcMinus(size_t first, size_t second) {
	return second - first;
}

size_t calcMult(size_t first, size_t second) {
	return second * first;
}

size_t calcDivide(size_t first, size_t second) {
	return second / first;
}

bool RPN::isOperator(char c) {
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	return false;
}

void RPN::pushPossibleValue(char c) {
	if (c == ' ')
		return ;
	if (isOperator(c))
		return ;
	if (!isdigit(c))
		throw std::runtime_error("Error");
	stack.push(c - 48);
}

size_t RPN::valuePoppedOut() {
	if (stack.empty())
		throw std::runtime_error("Error: valance between number and operator sign doesn't good.");
	size_t i = stack.top();
	stack.pop();
	return i;
}

void RPN::calc(char c) {
	size_t ret;
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

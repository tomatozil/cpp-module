#include "RPN.hpp"

RPN* RPN::instanceRPN = NULL;

int main(int argc, char *argv[]) {
	if (argc != 2) {
		std::cout << "Error: incorrect format.";
		return -1;
	}

	try {
		RPN* rpn = RPN::getInstance();
		std::string arg(argv[1]);
		std::string::iterator strIter = arg.begin();
		while (strIter != arg.end()) {
			if (RPN::isOperator(*strIter))
				rpn->calc(*strIter);
			rpn->pushPossibleValue(strIter);
			strIter++;
		}
		rpn->checkStack();
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
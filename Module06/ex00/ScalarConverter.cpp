#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &literal) {
	switch (whichType(literal)) {
		case CHAR:
			break;
		case INT:
			break;
		case FLOAT:
			break;
		case DOUBLE:
			break;
		case NONE:
			break;
	}
}

ScalarConverter::DataType ScalarConverter::whichType(const std::string &literal) {
	void (ScalarConverter::*f[4])() = {}
}

ScalarConverter::DataType ScalarConverter::isChar(const std::string &literal) {
	if (literal.length() == 1 && isascii(literal[0]))
		return (CHAR);
	return (NONE);
}

ScalarConverter::DataType ScalarConverter::isInt(const std::string &literal) {
	int a;
	std::stringstream stream(literal);
	stream >> a;
	if (32 >= a && a <= 127)
}

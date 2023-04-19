#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &literal) {
	switch (whichType(literal)) {
		case CHAR:
			convertChar(static_cast<char>(literal[0]));
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

void ScalarConverter::convertChar(char c) {
	std::cout << "char: \'" << c << "\'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

ScalarConverter::DataType ScalarConverter::whichType(const std::string &literal) {
	ScalarConverter::DataType (*f[4])(const std::string &literal) = {&isChar, &isInt, &isFloat, &isDouble};

	DataType tmp;
	for(int i = 0; i < 4; i++) {
		tmp = (*f[i])(literal);
		if (tmp != NONE)
			return (tmp);
	}
	return (NONE);
}

ScalarConverter::DataType ScalarConverter::isChar(const std::string &literal) {
	if (literal.length() == 1 && isascii(literal[0]))
		return (CHAR);
	return (NONE);
}

ScalarConverter::DataType ScalarConverter::isInt(const std::string &literal) {
	if (literal.find('.') != std::string::npos)
		return (NONE);
	std::stringstream stream(literal);
	int i;
	stream >> i;
	if (stream.fail())
		return (NONE);
	if (INT_MIN > i || i > INT_MAX)
		return (NONE);
	return (INT);
}

ScalarConverter::DataType ScalarConverter::isFloat(const std::string &literal) {
	if (literal.find('.') == std::string::npos)
		return (NONE);
	if (literal.find('f') == std::string::npos)
		return (NONE);
	std::string str = literal;
	size_t fPos = str.find('f');
	if (fPos != std::string::npos)
		str.resize(fPos);
	std::stringstream stream(str);
	float f;
	stream >> f;
	if (stream.fail())
		return (NONE);
	if (FLT_MIN > f || f > FLT_MAX)
		return (NONE);
	return (FLOAT);
}

ScalarConverter::DataType ScalarConverter::isDouble(const std::string &literal) {
	if (literal.find('.') == std::string::npos)
		return (NONE);
	std::stringstream stream(literal);
	double d;
	stream >> d;
	if (stream.fail())
		return (NONE);
	if (DBL_MIN > d || d > DBL_MAX)
		return (NONE);
	return (DOUBLE);
}

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}
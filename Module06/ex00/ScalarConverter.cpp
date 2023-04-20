#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &literal) {
	switch (whichType(literal)) {
		case CHAR:
			convertChar(static_cast<char>(literal[0]));
			break;
		case INT:
			convertInt(static_cast<int>(std::strtod(literal.c_str(), NULL)));
			break;
		case FLOAT:
			convertFloat(static_cast<float>(std::strtod(literal.c_str(), NULL)));
			break;
		case DOUBLE:
			convertDouble(static_cast<double>(std::strtod(literal.c_str(), NULL)));
			break;
		case NONE:
			convertNone();
			break;
	}
}

void ScalarConverter::convertChar(char c) {
	std::cout << "char: \'" << c << "\'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

void ScalarConverter::convertInt(int i) {
	if (32 < i && i < 127)
		std::cout << "char: \'" << static_cast<char>(i) << "\'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void ScalarConverter::convertFloat(float f) {
	int ftoi = static_cast<int>(f);
	if (32 < ftoi && ftoi < 127)
		std::cout << "char: \'" << static_cast<char>(ftoi) << "\'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << ftoi << std::endl;
	if (f - ftoi == 0)
		std::cout << "float: " << f << ".0f" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;
	if (f - ftoi == 0)
		std::cout << "double: " << static_cast<double>(f) << ".0" << std::endl;
	else
		std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void ScalarConverter::convertDouble(double d) {
	int dtoi = static_cast<int>(d);
	if (32 < dtoi && dtoi < 127)
		std::cout << "char: \'" << static_cast<char>(dtoi) << "\'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << dtoi << std::endl;
	if (d - dtoi == 0)
		std::cout << "float: " << d << ".0f" << std::endl;
	else
		std::cout << "float: " << d << "f" << std::endl;
	if (d - dtoi == 0)
		std::cout << "double: " << static_cast<double>(d) << ".0" << std::endl;
	else
		std::cout << "double: " << static_cast<double>(d) << std::endl;
}

void ScalarConverter::convertNone() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
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
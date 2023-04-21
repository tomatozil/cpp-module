#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &literal) {
	switch (whichType(literal)) {
		case CHAR:
			convertChar(static_cast<char>(literal[0]));
			break;
		case INT:
			convertInt(static_cast<int>(std::strtol(literal.c_str(), NULL, 10)));
			break;
		case FLOAT:
			convertFloat(static_cast<float>(std::strtod(literal.c_str(), NULL)));
			break;
		case DOUBLE:
			convertDouble(static_cast<double>(std::strtod(literal.c_str(), NULL)));
			break;
		case NONE:
			convertNone(literal);
			break;
	}
}

void ScalarConverter::convertChar(char c) {
	if (isprint(c))
		std::cout << "char: \'" << c << "\'\n";
	else
		std::cout << "char: Non displayable\n";
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConverter::convertInt(int i) {
	if (32 < i && i < 127)
		std::cout << "char: \'" << static_cast<char>(i) << "\'" << std::endl;
	else if ((0 <= i && i <= 32) || i == 127)
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char : impossible\n";
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void ScalarConverter::convertFloat(float f) {
	int ftoi = static_cast<int>(f);
	if (32 < ftoi && ftoi < 127)
		std::cout << "char: \'" << static_cast<char>(ftoi) << "\'" << std::endl;
	else if ((0 <= ftoi && ftoi <= 32) || ftoi == 127)
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char : impossible\n";
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
	else if ((0 <= dtoi && dtoi <= 32) || dtoi == 127)
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char : impossible\n";
	std::cout << "int: " << dtoi << std::endl;
	if (d - dtoi == 0)
		std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	if (d - dtoi == 0)
		std::cout << "double: " << d << ".0" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convertNone(const std::string &literal) {
	if (literal == "nan") {
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: nanf\n";
		std::cout << "double: nan\n";
	} else if (literal == "-inf" || literal == "-inff") {
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: -inff\n";
		std::cout << "double: -inf\n";
	} else if (literal == "inf" || literal == "inff") {
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: inff\n";
		std::cout << "double: inf\n";
	} else {
		std::cout << "Impossible to convert\n";
	}
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
	if (literal.length() != 1)
		return (NONE);
	if (isascii(literal[0]))
		if ('0' <= toascii(literal[0]) && toascii(literal[0]) <= '9')
			return (NONE);
	return (CHAR);
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

ScalarConverter::ScalarConverter(const ScalarConverter &origin) {(void)origin;}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &converter) {
	(void)converter;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}
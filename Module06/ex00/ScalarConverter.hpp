#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <iomanip>
#include <math.h>
#include <float.h>
#include <stdlib.h>

class ScalarConverter {
private:
  	enum DataType {CHAR, INT, FLOAT, DOUBLE, NONE};

public:
	static void convert(const std::string& literal);
	static int whichType(const std::string& literal);

	static int isChar(const std::string& literal);
	static int isInt(const std::string& literal);
	static int isFloat(const std::string& literal);
	static int isDouble(const std::string& literal);

	static void convertChar(char c);
	static void convertInt(int i);
	static void convertFloat(float f);
	static void convertDouble(double d);
	static void convertNone(const std::string &literal);

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& origin);
	ScalarConverter& operator=(const ScalarConverter& converter);
	~ScalarConverter();
};

#endif

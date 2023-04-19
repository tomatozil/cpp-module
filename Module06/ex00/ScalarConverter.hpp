#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <iomanip>
#include <cfloat>

class ScalarConverter {
private:
	typedef enum {CHAR, INT, FLOAT, DOUBLE, NONE} DataType;

public:
	static void convert(const std::string& literal);
	static DataType whichType(const std::string& literal);

	static DataType isChar(const std::string& literal);
	static DataType isInt(const std::string& literal);
	static DataType isFloat(const std::string& literal);
	static DataType isDouble(const std::string& literal);

	static void convertChar(char c);
//	static void convertInt(int i);
//	static void convertFloat(float f);
//	static void convertDouble(double d);

private:
	ScalarConverter();
//	ScalarConverter(const ScalarConverter& origin);
//	ScalarConverter& operator=(const ScalarConverter& converter);
	~ScalarConverter();
};

#endif

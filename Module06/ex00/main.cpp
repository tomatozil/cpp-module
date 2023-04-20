#include "ScalarConverter.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Enter 2 arguments(./[EXECUTE FILE] literal)" << std::endl;
		return (0);
	}
	ScalarConverter::convert(av[1]);
}

//int main() {
//	ScalarConverter::convertChar('c');
//	std::string str = "42.0f";
//	double d = strtod(str.c_str(), NULL);
//	size_t dotPos = str.find('.');
//	size_t fractionLen = str.length() - dotPos - 1;
//	std::cout << fractionLen << std::endl;
//	std::cout << d << std::endl;
//	std::cout << static_cast<int>(d) << std::endl;
//	std::cout << static_cast<float>(d) << std::endl;
//	if (fractionLen > 6)
//		std::cout << std::fixed << std::setprecision(6) << static_cast<float>(d) << std::endl;
//	else
//		std::cout << std::fixed << std::setprecision(fractionLen) << static_cast<float>(d) << std::endl;
//}

//int main() {
//	std::string s = "42.0f";
//	long a;
//	float f;
//	double d;
//
//	std::cout << "======= Str* Function =======" << std::endl;
//	a = std::stol(s, NULL, 10);
//	std::cout << "Int: " << a << std::endl;
//
//	f = std::stof(s, NULL);
//	std::cout << "Float: " << f << std::endl;
//	d = std::stod(s, NULL);
//	std::cout << "Double: " << d << std::endl;
//
//	std::stringstream stream(s);
//	int i;
//	float f1;
//	double d1;
//
//	std::cout << "======= StringStream =======" << std::endl;
//	stream >> i;
//	if (stream.fail()) {
//		std::cout << "it's fail" << std::endl;
//		return (0);
//	}
//	std::cout << "Int: " << i << std::endl;
//	stream.clear();
//
//	std::string str = s;
//	size_t fPos = str.find('f');
//	std::cout << "fPos: " << fPos << std::endl;
//	if (fPos != std::string::npos)
//		str.resize(fPos - 1);
//	stream.str(str);
//	stream >> f1;
//	std::cout << "Float: " << f1 << std::endl;
//	stream.clear();
//
//	stream.str(s);
//	stream >> d1;
//	std::cout << "Double: " << d1 << std::endl;
//
//	return 0;
//}

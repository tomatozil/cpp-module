#include <iostream>
#include <sstream>

int main() {
	std::string s = "3.124f";
	std::stringstream stream;
	int a;
	float f;
	double d;

	stream.str(s);
	std::cout << stream.str() << std::endl;
	stream >> f;
	std::cout << f << std::endl;
//	while(stream >> f)
//	{
//		std::cout << f << std::endl;
//	}
	std::stringstream ss("3.14");
	float f1;

	ss >> f1;

	if (ss.fail()) {
		std::cerr << "Error converting to float" << std::endl;
		return 1;
	}

	std::cout << "Float value: " << f1 << std::endl;

	return 0;
}

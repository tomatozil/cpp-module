#include "Span.hpp"
#include <array>

int main() {
	{
		std::cout << "test1: \n";
		try {
			Span sp = Span(5);
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}

	{
		std::cout << "test2: \n";
		try {
			std::array<int, 6> arr = {42, 24, 1, 21, 12, 2};
			Span sp2 = Span(6);
			sp2.addNumber(arr.begin(), arr.end());
			std::cout << sp2.shortestSpan() << std::endl;
			std::cout << sp2.longestSpan() << std::endl;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}

	{
		std::cout << "test3: \n";
		try {
			std::array<int, 1> arr = {7};
			Span sp2 = Span(1);
			sp2.addNumber(arr.begin(), arr.end());
			std::cout << sp2.shortestSpan() << std::endl;
			std::cout << sp2.longestSpan() << std::endl;
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}


	return 0;
}
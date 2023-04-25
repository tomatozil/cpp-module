#ifndef MODULE08_SPAN_HPP
#define MODULE08_SPAN_HPP

#include <iostream>
#include <vector>

class Span {
public:
	void addNumber(int number) throw(std::runtime_error);
	void addNumber(int *begin, int *end) throw(std::runtime_error);
	int shortestSpan() throw(std::runtime_error);
	int longestSpan() throw(std::runtime_error);

	Span(unsigned int N);
	Span(const Span& origin);
	Span& operator=(const Span& span);
	~Span();

private:
	Span();

private:
	unsigned int N;
	unsigned int curSize;
	std::vector<int> vec;
};

#endif

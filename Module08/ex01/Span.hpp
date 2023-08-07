#ifndef MODULE08_SPAN_HPP
#define MODULE08_SPAN_HPP

#include <iostream>
#include <vector>

class Span {
public:
	void addNumber(const int& number) throw(std::runtime_error);
	template<typename Iter>
	void addNumber(Iter begin, Iter end) throw(std::runtime_error) {
		unsigned int size = end - begin;
		if (size > N)
			throw std::runtime_error("Error: couldn't add that much.");
		vec.insert(vec.begin(), begin, end);
		curSize = size;
	}
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

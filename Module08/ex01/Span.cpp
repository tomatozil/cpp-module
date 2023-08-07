#include "Span.hpp"
#include <cstdlib>

void Span::addNumber(const int& number) throw(std::runtime_error) {
	if (curSize == N)
		throw std::runtime_error("Error: couldn't add more.");
	vec.push_back(number);
	curSize++;
}

int Span::shortestSpan() throw(std::runtime_error) {
	if (curSize < 2)
		throw std::runtime_error("Error: no span can be found.");
	int min = INT_MAX;
	std::vector<int>::iterator iter = vec.begin();
	while (iter + 1 != vec.end()) {
		int absValue = std::abs((*(iter + 1) - *iter));
		if (min >= absValue)
			min = absValue;
		iter++;
	}
	return (min);
}

int Span::longestSpan() throw(std::runtime_error) {
	if (curSize < 2)
		throw std::runtime_error("Error: no span can be found.");
	int max = INT_MIN;
	std::vector<int>::iterator iter = vec.begin();
	while (iter + 1 != vec.end()) {
		int absValue = std::abs((*(iter + 1) - *iter));
		if (max <= absValue)
			max = absValue;
		iter++;
	}
	return (max);
}

Span::Span(unsigned int N) : N(N), curSize(0) {}

Span::Span(const Span &origin) : N(origin.N), curSize(origin.curSize), vec(origin.vec) {
	this->vec.insert(this->vec.begin(), origin.vec.begin(), origin.vec.end());
}

Span& Span::operator=(const Span &span) {
	if (this == &span)
		return (*this);
	this->N = span.N;
	this->curSize = span.curSize;
	this->vec.insert(this->vec.begin(), span.vec.begin(), span.vec.end());
	return (*this);
}

Span::~Span() {}

Span::Span() {}

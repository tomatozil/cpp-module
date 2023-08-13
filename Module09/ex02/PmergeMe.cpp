#include "PmergeMe.hpp"

std::vector<int> PmergeMe::getVec() {
	return vec;
}

std::deque<int> PmergeMe::getDeq() {
	return deq;
}

PmergeMe::PmergeMe(char* argv[]) : vec(), deq() {
	giveValues(argv);
}

PmergeMe::~PmergeMe() {}

void PmergeMe::giveValues(char *argv[]) {
	int i = 0;
	while (argv[++i]) {
		int value = argv[i][0] - 48;
		if (value < 0)
			throw std::runtime_error("Error: negative integer is denied.");
		if (value > 9)
			throw std::runtime_error("Error: other than number is denied.");
		vec.push_back(value);
		deq.push_back(value);
	}
}

PmergeMe::PmergeMe(const PmergeMe &origin) : vec(origin.vec), deq(origin.deq) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& pmergeMe) {
	if (this == &pmergeMe)
		return (*this);
	if (this->vec != pmergeMe.vec) {
		this->vec = pmergeMe.vec;
	}
	if (this->deq != pmergeMe.deq) {
		this->deq = pmergeMe.deq;
	}
	return (*this);
}
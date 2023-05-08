#include "PmergeMe.hpp"

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

std::vector<int> PmergeMe::getVec() {
	return vec;
}

std::deque<int> PmergeMe::getDeq() {
	return deq;
}

PmergeMe* PmergeMe::getInstance() {
	if (instance == NULL)
		instance = new PmergeMe();
	return (instance);
}

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {
	delete instance;
}

PmergeMe::PmergeMe(const PmergeMe &origin) {
	(void)origin;
	delete this;
}
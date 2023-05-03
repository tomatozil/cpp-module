#ifndef MODULE09_PMERGEME_HPP
#define MODULE09_PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>

class PmergeMe {
public:
	void giveValues(char *argv[]);
	template<typename T>
	void sort(T arr, int f, int l);
	static PmergeMe* getInstance();

private:
	PmergeMe();
	PmergeMe(const PmergeMe& origin);
	PmergeMe& operator=(const PmergeMe& pmergeMe);
	~PmergeMe();

private:
	std::vector<int> vec;
	std::deque<int> deq;
	static PmergeMe* instance;
};

#endif
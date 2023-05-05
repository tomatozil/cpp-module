#include "PmergeMe.hpp"

template<typename T>
void PmergeMe::printValues(T& arr) {
	typename T::iterator iter;
	for(iter = arr.begin(); iter < arr.end(); iter++) {
		if (iter + 1 == arr.end())
			std::cout << *iter << std::endl;
		else
			std::cout << *iter << " ";
	}
}

template<typename T>
void merge(T& arr, int f, int m, int l) {
	int leftLen = m - f + 1;
	int rightLen = l - m;
	T left;
	for(int i = f; i < m + 1; i++)
		left.push_back(arr[i]);
	T right;
	for(int i = m + 1; i < l + 1; i++)
		right.push_back(arr[i]);
	int leftIdx = 0, rightIdx = 0;
	int k = f;
	while (leftIdx < leftLen && rightIdx < rightLen) {
		if (left[leftIdx] <= right[rightIdx])
			arr[k] = left[leftIdx++];
		else
			arr[k] = right[rightIdx++];
		k++;
	}
	while (leftIdx < leftLen)
		arr[k++] = left[leftIdx++];
	while (rightIdx < rightLen)
		arr[k++] = right[rightIdx++];
}

template<typename T>
void insert(T& arr, int f, int l) {
	for(int i = f; i < l; i++) {
		int targetValue = arr[i + 1];
		int j = i + 1;
		while (j > f && arr[j - 1] > targetValue) {
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = targetValue;
	}
}

template<typename T>
void PmergeMe::sort(T& arr, int f, int l) {
	if (l - f > 5) {
		int m = (f + l) / 2;
		sort(arr, f, m);
		sort(arr, m + 1, l);
		merge(arr, f, m, l);
	} else {
		insert(arr, f, l);
	}
}

void PmergeMe::giveValues(char **argv) {
	int i = 0;
	while (argv[++i]) {
		int value = argv[i][0] - 48;
		if (value < 0)
			throw std::runtime_error("Error: negative integer is denied.");
		if (value < 48 || value > 57)
			throw std::runtime_error("Error: other than number is denied.");
		vec.push_back(value);
		deq.push_back(value);
	}
}

std::vector<int>& PmergeMe::getVec() {
	return vec;
}

std::deque<int>& PmergeMe::getDeq() {
	return deq;
}

template<typename T>
size_t PmergeMe::getContainerSize(T &arr) {
	return arr.size();
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
	delete this;
}
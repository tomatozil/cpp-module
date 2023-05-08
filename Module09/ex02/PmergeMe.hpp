#ifndef MODULE09_PMERGEME_HPP
#define MODULE09_PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>

class PmergeMe {
public:
	void giveValues(char *argv[]);
	template<typename T>
	void printValues(T& arr) {
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
	void sort(T& arr, int f, int l) {
		if (l - f > 5) {
			int m = (f + l) / 2;
			sort(arr, f, m);
			sort(arr, m + 1, l);
			merge(arr, f, m, l);
		} else {
			insert(arr, f, l);
		}
	}
	std::vector<int> getVec();
	std::deque<int> getDeq();
	template<typename T>
	size_t getContainerSize(T& arr) {
		return arr.size();
	}
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
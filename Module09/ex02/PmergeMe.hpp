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
    int binarySearch(T& arr, int first, int last, int value) {
        int middle;
        while (first < last) {
            middle = first + ((last - first) / 2);
            if (value < arr[middle])
                last = middle;
            else
                first = middle + 1;
        }
        return last;
    }
	template<typename T>
	void insert(T& arr, int first, int last) {
        int size = last - first + 1;
		for(int i = 1; i < size; i++) {
			int targetValue = arr[first + i];
            int loc = binarySearch(arr, first, first + i, targetValue);
			int j = first + i - 1;
			while (j >= loc) {
				arr[j + 1] = arr[j];
				j--;
			}
			arr[loc] = targetValue;
		}
	}
	template<typename T>
	void sort(T& arr, int first, int last) {

		if (last - first > 5) {
			int middle = first + ((last - first) / 2);
			sort(arr, first, middle);
			sort(arr, middle + 1, last);
			std::inplace_merge(&arr[first], &arr[middle + 1], &arr[last + 1]);
		} else {
			insert(arr, first, last);
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
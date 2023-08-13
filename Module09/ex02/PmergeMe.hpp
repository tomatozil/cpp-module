#ifndef MODULE09_PMERGEME_HPP
#define MODULE09_PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>

class PmergeMe {
public:
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
	void merge_sort(T& arr, int first, int last) {

		if (last - first > 5) {
			int middle = first + ((last - first) / 2);
			merge_sort(arr, first, middle);
			merge_sort(arr, middle + 1, last);
			std::inplace_merge(arr.begin() + first, arr.begin() + middle + 1, arr.begin() + last + 1);
		} else {
			insert(arr, first, last);
		}
	}

//	template<typename T, typename Iter>
//	void merge_sort(T& arr, Iter first, Iter last) {
//
//		if (last - first > 5) {
//			Iter middle = first + ((last - first) / 2);
//			merge_sort(first, middle);
//			merge_sort(middle, last);
//			std::inplace_merge(first, middle, last);
//		} else {
//			insert(arr, first, last);
//		}
//	}


	template<typename T>
	size_t getContainerSize(T& arr) {
		return arr.size();
	}
	std::vector<int> getVec();
	std::deque<int> getDeq();

	PmergeMe(char *argv[]);
	~PmergeMe();

private:
	void giveValues(char *argv[]);
	PmergeMe(const PmergeMe& origin);
	PmergeMe& operator=(const PmergeMe& pmergeMe);

private:
	std::vector<int> vec;
	std::deque<int> deq;
};

#endif
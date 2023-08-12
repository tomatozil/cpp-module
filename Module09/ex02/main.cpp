#include "PmergeMe.hpp"
#include <ctime>

PmergeMe* PmergeMe::instance = NULL;

int main(int argc, char *argv[]) {
	if (argc < 2) {
		std::cout << "Error" << std::endl;
	}
	try {
		std::clock_t start_time, end_time;
		PmergeMe* pmergeMe = PmergeMe::getInstance();

		pmergeMe->giveValues(argv);

		std::vector<int> vec = pmergeMe->getVec();
		std::cout << "Vec Before:  ";
		pmergeMe->printValues(vec);
		start_time = std::clock();
		pmergeMe->sort(vec, 0, pmergeMe->getContainerSize(vec) - 1);
		end_time = std::clock();
		std::cout << "Vec After: ";
		pmergeMe->printValues(vec);
		double exec_time =(double)(end_time - start_time) / (double)1000;
		std::cout << "Time to process a range of  " << pmergeMe->getContainerSize(vec) << " elements with std::vector : " << exec_time << std::endl;

		std::deque<int> deq = pmergeMe->getDeq();
		std::cout << "Deq Before:  ";
		pmergeMe->printValues(deq);
		start_time = std::clock();
		pmergeMe->sort(deq, 0, pmergeMe->getContainerSize(deq) - 1);
		end_time = std::clock();
		std::cout << "Deq After:  ";
		pmergeMe->printValues(deq);
		exec_time =(double)(end_time - start_time) / (double)1000;
		std::cout << "Time to process a range of  " << pmergeMe->getContainerSize(deq) << " elements with std::deque : " << exec_time << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
:q}

//#include <iostream>
//#include <vector>
//#include <deque>
//
//template<typename T>
//void merge(T& arr, int f, int m, int l) {
//	int leftLen = m - f + 1;
//	int rightLen = l - m;
//	T left;
//	for(int i = f; i < m + 1; i++)
//		left.push_back(arr[i]);
//	T right;
//	for(int i = m + 1; i < l + 1; i++)
//		right.push_back(arr[i]);
//	int leftIdx = 0, rightIdx = 0;
//	int k = f;
//	while (leftIdx < leftLen && rightIdx < rightLen) {
//		if (left[leftIdx] <= right[rightIdx])
//			arr[k] = left[leftIdx++];
//		else
//			arr[k] = right[rightIdx++];
//		k++;
//	}
//	while (leftIdx < leftLen)
//		arr[k++] = left[leftIdx++];
//	while (rightIdx < rightLen)
//		arr[k++] = right[rightIdx++];
//}
//
//template<typename T>
//void insert(T& arr, int f, int l) {
//	for(int i = f; i < l; i++) {
//		int targetValue = arr[i + 1];
//		int j = i + 1;
//		while (j > f && arr[j - 1] > targetValue) {
//			arr[j] = arr[j - 1];
//			j--;
//		}
//		arr[j] = targetValue;
//	}
//}
//
//template<typename T>
//void sort(T& arr, int f, int l) {
//	if (l - f > 1) {
//		int m = (f + l) / 2;
//		sort(arr, f, m);
//		sort(arr, m + 1, l);
//		merge(arr, f, m, l);
//	} else {
//		insert(arr, f, l);
//	}
//}
//
//int main() {
//	std::vector<int> vec;
//	vec.push_back(5);
//	vec.push_back(2);
//	vec.push_back(1);
//	vec.push_back(7);
//	vec.push_back(6);
//	sort(vec, 0, vec.size() - 1);
//	std::vector<int>::iterator iter1;
//	for(iter1 = vec.begin(); iter1 != vec.end(); iter1++)
//		std::cout << *iter1 << " ";
//	std::deque<int> deq;
//	deq.push_back(5);
//	deq.push_back(2);
//	deq.push_back(1);
//	deq.push_back(7);
//	deq.push_back(6);
//	sort(deq, 0, deq.size() - 1);
//	std::deque<int>::iterator iter2;
//	std::cout << "\n" << std::endl;
//	for(iter2 = deq.begin(); iter2 != deq.end(); iter2++)
//		std::cout << *iter2 << " ";
//}
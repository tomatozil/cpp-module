//#include "PmergeMe.hpp"
//
//PmergeMe* PmergeMe::instance = NULL;
//
//int main(int argc, char *argv[]) {
//	if (argc < 2) {
//		std::cout << "Error" << std::endl;
//	}
//	// before 출력
//	// 벡터 시작 타임
//	// sort
//	// 끝 타임
//
//	// 뎈 시작 타임
//	// sort
//	// 끝 타임
//
//	// after 출력
//	//벡터 시작타임 - 끝타임 출력
//	//뎈 시작타임 - 끝타임 출력
//	try {
//		PmergeMe* pmergeMe = PmergeMe::getInstance();
//		pmergeMe->giveValues(argv);
//
//	} catch (std::exception& e) {
//		std::cout << e.what() << std::endl;
//	}
//}

#include <iostream>
#include <vector>

template<typename T>
void merge(T arr, int f, int m, int l) {
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
void insert(T arr, int f, int l) {
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
void sort(T arr, int f, int l) {
	if (l - f > 5) {
		int m = (f + 1) / 2;
		sort(arr, f, m);
		sort(arr, m + 1, l);
		merge(arr, f, m, l);
	} else {
		insert(arr, f, l);
	}
}

int main() {
	std::vector<int> arr;
	arr.push_back(5);
	arr.push_back(2);
	arr.push_back(1);
	arr.push_back(7);
	arr.push_back(6);
	sort(arr, 0, arr.size() - 1);
	std::vector<int>::iterator iter;
	for(iter = arr.begin(); iter != arr.end(); iter++)
		std::cout << *iter << std::endl;
}
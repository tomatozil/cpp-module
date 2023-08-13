#include "PmergeMe.hpp"
#include <ctime>

int main(int argc, char *argv[]) {
	if (argc < 2) {
		std::cout << "Error" << std::endl;
		return -1;
	}
	try {
		std::clock_t start_time, end_time;
		PmergeMe pmergeMe(argv);

		std::vector<int> vec = pmergeMe.getVec();
		std::cout << "Before: ";
		pmergeMe.printValues(vec);
		start_time = std::clock();
		pmergeMe.merge_sort(vec, 0, pmergeMe.getContainerSize(vec) - 1);
		end_time = std::clock();
		std::cout << "After: ";
		pmergeMe.printValues(vec);
		double exec_time =(double)(end_time - start_time) / (double)1000;
		std::cout << "Time to process a range of  " << pmergeMe.getContainerSize(vec) << " elements with std::vector : " << exec_time << std::endl;

		std::deque<int> deq = pmergeMe.getDeq();
		start_time = std::clock();
		pmergeMe.merge_sort(deq, 0, pmergeMe.getContainerSize(deq) - 1);
		end_time = std::clock();
		exec_time =(double)(end_time - start_time) / (double)1000;
		std::cout << "Time to process a range of  " << pmergeMe.getContainerSize(deq) << " elements with std::deque : " << exec_time << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
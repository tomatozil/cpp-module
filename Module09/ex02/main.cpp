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
}
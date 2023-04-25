#include <iostream>
#include "Array.tpp"
//#include <stdlib.h>
#define MAX_VAL 750

int main(int, char**)
{
//	void *a;
//
//	a = malloc(UINT_MAX);
//	while (a)
//		a = malloc(UINT_MAX);
//	a = malloc(1);
//	while (a)
//		a = malloc(1);
//	try {
		Array<int> numbers(MAX_VAL);
		int* mirror = new int[MAX_VAL];
		srand(time(NULL));
		for (int i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		//SCOPE
		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			if (mirror[i] != numbers[i])
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
		try
		{
			numbers[-2] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		try
		{
			numbers[MAX_VAL] = 0;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		for (int i = 0; i < MAX_VAL; i++)
		{
			numbers[i] = rand();
		}
		delete [] mirror;
//	}
//	catch (std::exception &e) {
//		std::cout << e.what() << std::endl;
//	}

	return 0;
}
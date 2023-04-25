#ifndef MODULE07_ITER_HPP
#define MODULE07_ITER_HPP

#include <iostream>

template<typename T>
void iter(T* arr, size_t arr_len, void (*f)(T)) {
	for(size_t i = 0; i < arr_len; i++)
		(*f)(arr[i]);
}

template<typename T>
void print(T value) {
	std::cout << value;
}

#endif

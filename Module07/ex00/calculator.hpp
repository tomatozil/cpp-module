#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <iostream>

template<typename T>
void swap(T& v1, T& v2) {
	T tmp = v1;
	v1 = v2;
	v2 = tmp;
}

template<typename T>
T& min(T& v1, T& v2) {
	if (v1 >= v2)
		return v2;
	return v1;
}

template<typename T>
T& max(T& v1, T& v2) {
	if (v1 > v2)
		return v1;
	return v2;
}

#endif
#include "Array.hpp"

template<typename T>
unsigned int Array<T>::size() const {
	return n;
}

template<typename T>
void Array<T>::print() {
	for(unsigned int i = 0; i < n; i++)
		std::cout << arr[i] << "\n";
}

template<typename T>
Array<T>::Array() : n(0), arr(new T) {}

template<typename T>
Array<T>::Array(unsigned int n) : n(n), arr(new T[n]) {}

template<typename T>
Array<T>::Array(const Array& origin) : n(origin.n), arr(new T[n]) {
	for(unsigned int i = 0; i < n; i++)
		arr[i] = origin.arr[i];
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& array) {
	if (this == &array)
		return (*this);
	this->n = array.n;
	this->arr = new T[n];
	for(unsigned int i = 0; i < n; i++)
		this->arr[i] = array.arr[i];
	return (*this);
}

template<typename T>
T& Array<T>::operator[](unsigned int idx) throw(std::range_error) {
	if (idx >= n)
		throw std::range_error("Error: Out of Index");
	return (arr[idx]);
}

template<typename T>
Array<T>::~Array() {
	delete arr;
}
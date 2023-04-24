#ifndef MODULE07_ARRAY_HPP
#define MODULE07_ARRAY_HPP

#include <iostream>

template<typename T>
class Array {
public:
	unsigned int size() const;
	void print();

	Array();
	Array(unsigned int n);
	Array(const Array& origin);
	Array& operator=(const Array& array);
	T& operator[](unsigned int idx) throw(std::range_error);
	~Array();

private:
	unsigned int n;
	T* arr;
};

#endif

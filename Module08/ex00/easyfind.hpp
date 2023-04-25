#ifndef MODULE08_EASYFIND_HPP
#define MODULE08_EASYFIND_HPP

#include <iostream>

template<typename T>
int easyfind(T container, int value) throw(std::invalid_argument) {
	typename T::iterator iterator = container.begin();
	// T::iterator-> dereferencing iterator obtains the container's value_type

	while (iterator != container.end()) {
		if (*iterator == value)
			return (value);
		iterator++; // sequence container
	}
	throw std::invalid_argument("Error: Container doesn't have the value");
}

#endif

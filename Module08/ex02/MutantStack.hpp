#ifndef MODULE08_MUTANTSTACK_HPP
#define MODULE08_MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T> {
public:
	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin() {
		return this->c.begin();
	}
	iterator end() {
		return this->c.end();
	}

	MutantStack() : std::stack<T>() {}
	MutantStack(const MutantStack& origin) : std::stack<T>(origin) {}
	MutantStack& operator=(const MutantStack& mutantStack) {
		if (this != &mutantStack)
			std::stack<T>::operator=(mutantStack);
		return *this;
	}
	~MutantStack() {}
};

#endif
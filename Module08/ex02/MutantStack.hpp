#ifndef MODULE08_MUTANTSTACK_HPP
#define MODULE08_MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T> {
public:
	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin() {
		return std::stack<T>::c.begin();
	}
	iterator end() {
		return std::stack<T>::c.end();
	}

	MutantStack() : std::stack<T>() {}
	MutantStack(const std::deque<T>& c) : std::stack<T>(c) {}
	MutantStack(const MutantStack& origin) : std::stack<T>(origin) {}
	MutantStack& operator=(const MutantStack& mutantStack) {
		if (this != &mutantStack)
			std::stack<T>::operator=(mutantStack);
		return *this;
	}
	~MutantStack() {}
};

#endif
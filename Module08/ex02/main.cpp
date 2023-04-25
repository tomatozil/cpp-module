#include "MutantStack.hpp"

#include <list>

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl; //17
	mstack.pop(); //17 없애고
	std::cout << mstack.size() << std::endl; //1
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	mstack.push(8); //[bottom] 5 - 3 - 5 - 737 - 0 - 8 [top]
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	std::cout << "begin + 1: " << *it << std::endl;
	--it;
	std::cout << "begin - 1: " << *it << std::endl;

	std::cout << "In while: \n";
	while (it != ite) {
		std::cout << "*it: " << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);
	std::cout << "s's top: " << s.top() << std::endl;
	std::cout << "s's size: " << s.size() << std::endl;

//	std::list<int> mslist;
//	mslist.push_back(5);
//	mslist.push_back(17);
//	std::cout << mslist.back() << std::endl; //17
//	mslist.pop_back(); //17 없애고
//	std::cout << mslist.size() << std::endl; //1
//	mslist.push_back(3);
//	mslist.push_back(5);
//	mslist.push_back(737);
//	//[...]
//	mslist.push_back(0);
//	mslist.push_back(8); //[front] 5 - 3 - 5 - 737 - 0 - 8 [back]
//	std::list<int>::iterator it = mslist.begin();
//	std::list<int>::iterator ite = mslist.end();
//	++it;
//	std::cout << "begin + 1: " << *it << std::endl;
//	--it;
//	std::cout << "begin - 1: " << *it << std::endl;
//
//	std::cout << "In while: \n";
//	while (it != ite) {
//		std::cout << "*it: " << *it << std::endl;
//		++it;
//	}
	return 0;
}

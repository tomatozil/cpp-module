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
	std::cout << "begin + 1 - 1: " << *it << std::endl;

	std::cout << "While: \n";
	while (it != ite) {
		std::cout << "*it: " << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	std::cout << "s's top: " << s.top() << std::endl;
	std::cout << "s's size: " << s.size() << std::endl;

	std::cout << "------------------------------------------------------" << "\n";

	std::list<int> mslist;
	mslist.push_back(5);
	mslist.push_back(17);
	std::cout << mslist.back() << std::endl; //17
	mslist.pop_back(); //17 없애고
	std::cout << mslist.size() << std::endl; //1
	mslist.push_back(3);
	mslist.push_back(5);
	mslist.push_back(737);
	//[...]
	mslist.push_back(0);
	mslist.push_back(8); //[front] 5 - 3 - 5 - 737 - 0 - 8 [back]
	std::list<int>::iterator it2 = mslist.begin();
	std::list<int>::iterator ite2 = mslist.end();
	++it2;
	std::cout << "begin + 1: " << *it2 << std::endl;
	--it2;
	std::cout << "begin + 1- 1: " << *it2 << std::endl;

	std::cout << "While: \n";
	while (it2 != ite2) {
		std::cout << "*it: " << *it2 << std::endl;
		++it2;
	}
	std::list<int> l(mslist);
	std::cout << "s's top: " << l.back() << std::endl;
	std::cout << "s's size: " << l.size() << std::endl;

	return 0;
}

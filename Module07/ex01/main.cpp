#include "iter.hpp"

int main() {
	std::string arr[5] = {"h", "e", "l", "l", "o"};
	int arr2[5] = {1, 2, 3, 4, 5};

	::iter(arr, 5, ::print);
	std::cout << "\n";
	::iter(arr2, 5, ::print);
}
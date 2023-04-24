#include "iter.hpp"

int main() {
	std::string arr[5] = {"h", "e", "l", "l", "o"};

	::iter(arr, 5, ::print);
}
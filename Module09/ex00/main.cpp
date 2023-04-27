#include "BitCoinChange.hpp"

bool isExtensionGood(const char *filename, const char *extension) {
	const char *dotPos = strrchr(filename, '.');
	if (!dotPos)
		return false;
	if (!strcmp(dotPos, extension))
		return false;
	return true;
}

int main(int ac, char **av) {
	// .txt 파일 유효성
	if (ac != 2)
		return 1;
	try {
		if (!isExtensionGood(av[1], ".txt"))
			throw ;

	}

	// .csv -> std::map database, .txt -> std::map inputfile

	// inputfile의 key와 같거나 작은 database key를 찾고, value끼리 곱하기
}

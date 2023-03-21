#include "Fixed.hpp"

int main() {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << --a << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	Fixed c = Fixed(12.5f);
	std::cout << c << std::endl;
	Fixed d = Fixed(25);
	std::cout << d << std::endl;
	std::cout << c + d << std::endl;
	std::cout << c - d << std::endl;
	std::cout << d - c << std::endl;
	std::cout << c / d << std::endl;
	std::cout << c * d << std::endl;
	Fixed e(c);
	std::cout << (c < e) << " " << (c < d) << " " << (d < c) << std::endl;
	std::cout << (c > e) << " " << (c > d) << " " << (d > c) << std::endl;
	std::cout << (c <= e) << " " << (c <= d) << " " << (d <= c) << std::endl;
	std::cout << (c >= e) << " " << (c >= d) << " " << (d >= c) << std::endl;
	std::cout << (c == e) << " " << (c == d) << " " << (d == c) << std::endl;
	std::cout << (c != e) << " " << (c != d) << " " << (d != c) << std::endl;
	std::cout << Fixed::min(c, d) << std::endl;
	return 0;
}

#include "Fixed.hpp"

void Fixed::setRawBits(const int raw) {
	fixedPointValue = raw;
}

int Fixed::getRawBits() const {
	return (fixedPointValue);
}

int Fixed::toInt() const {
	return (fixedPointValue >> fractionalBits);
}

float Fixed::toFloat() const {
	return ((float)fixedPointValue / (1 << fractionalBits));
}

Fixed::Fixed(const int i) : fixedPointValue(i << fractionalBits) {
	std::cout << "Int constructor called." << std::endl;
}

Fixed::Fixed(const float f) : fixedPointValue((int)(roundf(f * (1 << fractionalBits)))) {
	std::cout << "Float constructor called." << std::endl;
}

Fixed::Fixed(const Fixed &origin) {
	std::cout << "Copy constructor called." << std::endl;
	*this = origin;
}

Fixed &Fixed::operator=(const Fixed &origin) {
	std::cout << "Copy assignation operator called." << std::endl;
	fixedPointValue = origin.getRawBits();
	return (*this);
}

Fixed::Fixed() {
	std::cout << "Default constructor called." << std::endl;
	fixedPointValue = 0;
}

Fixed::~Fixed() {
	std::cout << "Destructor called." << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Fixed& origin) {
	return os << origin.toFloat();
}
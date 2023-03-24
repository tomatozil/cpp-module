#include "Fixed.hpp"

void Fixed::setRawBits(const int raw) {
	fixedPointValue = raw;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called." << std::endl;
	return (fixedPointValue);
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
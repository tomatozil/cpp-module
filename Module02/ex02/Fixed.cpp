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

Fixed::Fixed(const int i) : fixedPointValue(i << fractionalBits) {}

Fixed::Fixed(const float f) : fixedPointValue((int)(roundf(f * (1 << fractionalBits)))) {}

Fixed::Fixed(const Fixed &origin) {
	*this = origin;
}

Fixed& Fixed::operator=(const Fixed &fixed) {
	fixedPointValue = fixed.getRawBits();
	return (*this);
}

Fixed::Fixed() {
	fixedPointValue = 0;
}

Fixed::~Fixed() {}

bool Fixed::operator>(const Fixed &other) {
	return (fixedPointValue > other.getRawBits());
}

bool Fixed::operator<(const Fixed &other) {
	return (fixedPointValue < other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other) {
	return (fixedPointValue >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed &other) {
	return (fixedPointValue <= other.getRawBits());
}

bool Fixed::operator==(const Fixed &other) {
	return (fixedPointValue == other.getRawBits());
}

bool Fixed::operator!=(const Fixed &other) {
	return (fixedPointValue != other.getRawBits());
}

Fixed Fixed::operator+(const Fixed &other) {
	Fixed ret;

	ret.setRawBits(fixedPointValue + other.getRawBits());
	return (ret);
}

Fixed Fixed::operator-(const Fixed &other) {
	Fixed ret;

	ret.setRawBits(fixedPointValue - other.getRawBits());
	return (ret);
}

Fixed Fixed::operator*(const Fixed &other) {
	Fixed ret;

	ret.setRawBits(fixedPointValue * other.getRawBits() / (1 << fractionalBits));
	return (ret);
}

Fixed Fixed::operator/(const Fixed &other) {
	Fixed ret;

	ret.setRawBits(fixedPointValue / other.getRawBits() / (1 << fractionalBits));
	return (ret);
}

Fixed& Fixed::operator++() {
	++fixedPointValue;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
//	Fixed tmp = *this;

	++fixedPointValue;
	return (tmp);
}

Fixed& Fixed::operator--() {
	--fixedPointValue;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
//	Fixed tmp = *this;

	--fixedPointValue;
	return (tmp);
}

Fixed& Fixed::min(Fixed &fixed1, Fixed &fixed2) {
	if (fixed1.getRawBits() < fixed2.getRawBits())
		return (fixed1);
	return (fixed2);
}

Fixed& Fixed::max(Fixed &fixed1, Fixed &fixed2) {
	if (fixed1.getRawBits() > fixed2.getRawBits())
		return (fixed1);
	return (fixed2);
}

const Fixed& Fixed::min(const Fixed &fixed1, const Fixed &fixed2) {
	if (fixed1.getRawBits() < fixed2.getRawBits())
		return (fixed1);
	return (fixed2);
}

const Fixed& Fixed::max(const Fixed &fixed1, const Fixed &fixed2) {
	if (fixed1.getRawBits() > fixed2.getRawBits())
		return (fixed1);
	return (fixed2);
}

std::ostream& operator<<(std::ostream& os, const Fixed& origin) {
	return os << origin.toFloat();
}
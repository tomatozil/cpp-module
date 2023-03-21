#ifndef FIXED_H_
#define FIXED_H_

#include <iostream>
#include <math.h>

class Fixed {

public:
	Fixed();
	void setRawBits(int const raw);
	int getRawBits() const;
	float toFloat() const;
	int toInt() const;

	bool operator>(const Fixed& other);
	bool operator<(const Fixed& other);
	bool operator>=(const Fixed& other);
	bool operator<=(const Fixed& other);
	bool operator==(const Fixed& other);
	bool operator!=(const Fixed& other);

	Fixed operator+(const Fixed& other);
	Fixed operator-(const Fixed& other);
	Fixed operator*(const Fixed& other);
	Fixed operator/(const Fixed& other);

	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);

	static Fixed& min(Fixed& fixed1, Fixed& fixed2);
	static Fixed& max(Fixed& fixed1, Fixed& fixed2);
	static const Fixed& min(const Fixed& fixed1, const Fixed& fixed2);
	static const Fixed& max(const Fixed& fixed1, const Fixed& fixed2);

	explicit Fixed(const int i);
	explicit Fixed(const float f);
	Fixed(const Fixed& origin);
	Fixed& operator=(const Fixed& fixed);
	~Fixed();

private:
	int fixedPointValue;
	const static int fractionalBits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& origin);

#endif

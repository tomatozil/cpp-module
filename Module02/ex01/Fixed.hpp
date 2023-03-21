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
	explicit Fixed(const int i);
	explicit Fixed(const float f);
	Fixed(const Fixed& origin);
	Fixed& operator=(const Fixed& origin);
	~Fixed();

private:
	int fixedPointValue;
	const static int fractionalBits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& origin);

#endif

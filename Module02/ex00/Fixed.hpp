#ifndef FIXED_H_
#define FIXED_H_

#include <iostream>

class Fixed {

public:
	void setRawBits(int const raw);
	int getRawBits() const;
	Fixed();
	Fixed(const Fixed& origin);
	Fixed& operator=(const Fixed& origin);
	~Fixed();

private:
	int fixedPointValue;
	const static int fractionalBits = 8;
};

#endif

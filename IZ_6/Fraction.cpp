#include "Fraction_IZ_6.h"
#include <algorithm>

RationalNumber::RationalNumber(int x, unsigned int y) : x(x), y(y) {}

int RationalNumber::get_numerator() { 
	return x; 
}

int RationalNumber::get_denominator() {
	return y;
}

int RationalNumber::get_nod() {
	int nod = 1;
	for (int i = 2; i <= std::min(abs(x), abs(y)); i++)
		if (abs(x) % i == 0 && abs(y) % i == 0)
			nod = i;
	return nod;
}

void RationalNumber::reduction() {
	int nod = get_nod();
	x /= nod;
	y /= nod;
	if ((x < 0 && y < 0) || (x > 0 && y < 0)) {
		x *= -1;
		y *= -1;
	}
}

RationalNumber RationalNumber::get_sum(RationalNumber number) {
	RationalNumber sum(x * number.y + number.x * y, y * number.y);
	sum.reduction();
	return sum;
}

RationalNumber RationalNumber::get_sub(RationalNumber number) {
	RationalNumber sub(x * number.y - y * number.x, y * number.y);
	sub.reduction();
	return sub;
}

RationalNumber RationalNumber::get_mult(RationalNumber number) {
	RationalNumber mult(x * number.x, y * number.y);
	mult.reduction();
	return mult;
}

RationalNumber RationalNumber::get_quotient(RationalNumber number) {
	RationalNumber quotient(x * number.y, y * number.x);
	quotient.reduction();
	return quotient;
}
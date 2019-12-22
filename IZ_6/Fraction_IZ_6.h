#pragma once
#include <ostream>

class RationalNumber {

public:
	RationalNumber(int x, unsigned int y);
	RationalNumber get_sum(RationalNumber number);
	RationalNumber get_sub(RationalNumber number);
	RationalNumber get_mult(RationalNumber number);
	RationalNumber get_quotient(RationalNumber number);

	friend std::ostream& operator <<(std::ostream& os, const RationalNumber& n);
	
private:
	int x;
	int y;
	int get_numerator();
	int get_denominator();
	int get_nod();
	void reduction();
};
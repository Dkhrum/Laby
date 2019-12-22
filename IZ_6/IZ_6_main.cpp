
#include "Fraction_IZ_6.h"
#include <iostream>

using namespace std;

std::ostream& operator <<(std::ostream& os, const RationalNumber& n) {
	cout << n.x << "/" << n.y << endl;
	return os;
}

int main() {
	cout << "For the first and second fraction x/y type input x, y" << endl;
	int x_1, y_1, x_2, y_2;
	cin >> x_1 >> y_1 >> x_2 >> y_2;

	if (y_1 == 0 || y_2 == 0)
		cout << "ERROR" << endl;

	else {
		RationalNumber num_1(x_1, y_1), num_2(x_2, y_2);

		cout << "\nsum: \n" << num_1.get_sum(num_2) << endl;
		cout << "difference: \n" << num_1.get_sub(num_2) << endl;
		cout << "composition: \n" << num_1.get_mult(num_2) << endl;
		cout << "quotient: \n" << num_1.get_quotient(num_2) << endl;
	}
}
#include <iostream>
using namespace std;

double fact (int i) {
	if (i == 0)
		return 1;
	else return i * fact(i - 1);
}

int main() {
	double x, s = 0, res = 0;

	int k, i = 1;
	cout << "Enter 'x' to calculate sh(x) \n";
	cin >> x;
	cout << "Enter 'k', the accuracy of calculations \n";
	cin >> k;
	do {
		s = pow(x, i) / fact(i);
		res += s;
		i += 2;
	} while (abs(s) > pow(10, -k));
	cout << "sh(x)=" << res;
	return 0;
}
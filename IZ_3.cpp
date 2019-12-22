#include <iostream>
using namespace std;

int main() {
	int SizeI, SizeJ;
	cout << "enter the number of rows\n";
	cin >> SizeI;
	cout << "enter the number of columns\n";
	cin >> SizeJ;

	SizeI += 1;

	int** arr = new int* [SizeI];
	for (int i = 0; i < SizeI; i++) {
		arr[i] = new int[SizeJ];
	}

	cout << "\n\n";
	for (int i = 0; i < SizeI; i++) {
		for (int j = 0; j < SizeJ; j++) {
			if (i == SizeI - 1) {
				arr[i][j] = 0;
			}
			else if ((i + j) % 2 == 0)
				arr[i][j] = 10;
			else {
				cout << "enter element (" << i << "," << j << ")\n";
				cin >> arr[i][j];
			}
		}
	}

	cout << "\n\nYour array:\n";
	for (int i = 0; i < SizeI - 1; i++) {
		for (int j = 0; j < SizeJ; j++) {
			cout << arr[i][j] << "  ";
		}
		cout << "\n";
	}

	for (int j = 0; j < SizeJ; j++) {
		for (int i = 0; i < SizeI - 1; i++) {
			arr[SizeI - 1][j] += arr[i][j];
		}
	}

	int* tmp = new int[SizeI];

	
	for (int k = 0; k < SizeJ; k++) {
		for (int j = 0; j < SizeJ - 1; j++) {
			if (arr[SizeI - 1][j] > arr[SizeI - 1][j + 1]) {
				for (int j = 0; j < SizeJ - 1; j++) {
					for (int i = 0; i < SizeI; i++) {
						int temp = arr[i][j];
						arr[i][j] = arr[i][j + 1];
						arr[i][j + 1] = temp;
					}
				}
			}
		}
	}

	cout << "\n\nSorted array:\n";
	for (int i = 0; i < SizeI - 1; i++) {
		for (int j = 0; j < SizeJ; j++) {
			cout << arr[i][j] << "  ";
		}
		cout << "\n";
	}

	for (int i = 0; i < SizeI - 1; i++) {
		int ct = 0;
		for (int j = 0; j < SizeJ; j++) {
			if (arr[i][j] >= 0) {
				ct += 1;
			}
		}
		if (ct == SizeJ) {
			cout << "\n\nThe number of the line that does not contain negative elements:\n" << i;
			break;
		}
	}

	for (int i = 0; i < SizeI; i++) {
		delete[] arr[i];
	}
	return 0;
}
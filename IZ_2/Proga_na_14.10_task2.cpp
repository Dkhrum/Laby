#include <iostream>
using namespace std;

int main()
{
	int array_size;
	cout << "Enter array size :";
	cin >> array_size;
	if (array_size <= 0) return 0;

	int* arr = new int[array_size];

	cout << "Enter the elements...\n";
	for (int i = 0; i < array_size; i++) {
		cout << "arr [" << i + 1 << "]=";
		cin >> arr[i];
	};

	int ArrMin = arr[0];
	int ArrMax = arr[0];
	int IndexOfArrMin, IndexOfArrMax;
	for (int i = 0; i < array_size; i++) {
		if (arr[i] < ArrMin) {
			ArrMin = arr[i];
			IndexOfArrMin = i;
		}
		if (arr[i] >= ArrMax) {
			ArrMax = arr[i];
			IndexOfArrMax = i;
		}
	}

	double proizv = 1;
	for (int i = (IndexOfArrMin + 1); i < IndexOfArrMax; i++) {
		proizv *= arr[i];
	}
	
	cout << proizv;
	
	delete[] arr;
	return 0;
}
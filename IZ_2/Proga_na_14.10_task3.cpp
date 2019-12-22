#include <iostream>
#include <ctime>
using namespace std;

void BubbleSort(int* arr, int array_size) {
	int temp;
	for (int i = 0; i < array_size; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < array_size - 1; j++) {
				if (j % 2 == 0 && arr[j] > arr[j + 2]) {
					temp = arr[j];
					arr[j] = arr[j + 2];
					arr[j + 2] = temp;
				}
			}
		}
		else i++;
	}
	return;
}

int main() {
	int array_size;
	cout << "Enter array size: \n";
	cin >> array_size;
	if (array_size <= 0) return 0;

	int* arr = new int[array_size];

	cout << "\nto enter elements manually enter 1\n" << "to enter random elements enter 2\n";
	int choise;
	cin >> choise;
	cout << "\nyour array: \n";
	if (choise == 1) {
		cout << "Enter the elements...\n";
		for (int i = 0; i < array_size; i++) {
			cout << "arr [" << i + 1 << "]=";
			cin >> arr[i];
		}
	}
	if (choise == 2) {
		srand(time(NULL));
		for (int i = 0; i < array_size; i++) {
			arr[i] = rand() % 1000;
			cout << arr[i] << " ";
		}
	}
	else return 0;

	BubbleSort(arr, array_size);

	cout << "\n\nsorted array:\n";
	for (int i = 0; i < array_size; i++) {
		cout << arr[i] << " ";
	}

	delete[] arr;
	return 0;
}
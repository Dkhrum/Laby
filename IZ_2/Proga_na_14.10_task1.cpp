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
		cout << "arr [" << i+1 << "]=";
		cin >> arr[i];
	};

	// вывод массива
	cout << "\n Array before : ";
	for (int i = 0; i < array_size - 1; i++) cout << arr[i] << ", ";
	cout << arr[array_size - 1] << "\n";

	int Badness, BadnessMax;
	int IndexOfBadElement = 0; 

	while (IndexOfBadElement >= 0) {

		// вычислим "негодность" каждого элемента и индекс главного неподходящего
		IndexOfBadElement = -1;
		BadnessMax = 0;

		for (int i = 0; i < array_size; i++) {
			Badness = 0;
			if (arr[i] != 0) {
				for (int j = 0; j < array_size; j++)
					if (arr[j] != 0 && ((j < i && arr[j] >= arr[i]) || (j > i && arr[j] <= arr[i])))
						Badness++;
			}
			if (Badness > BadnessMax) {
				BadnessMax = Badness;
				IndexOfBadElement = i;
			}
		}

		if (IndexOfBadElement >= 0) {
			// обнуление неподходящих элементов
			arr[IndexOfBadElement] = 0;
		}
	}

	// вывод массива после обработки
	cout << "\n Array after  : ";
	for (int i = 0; i < array_size; i++) {
		if (arr[i] != 0)
			cout << arr[i] << ", ";
		else i++;
	}
	system("pause");
	delete[] arr;
	return 0;
}
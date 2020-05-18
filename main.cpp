#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::cerr;
using std::cin;
using std::setw;

void SelectionSort(int* data, size_t size);
void InsertionSort(int* data, size_t size);
void PrintArray(const int* data, size_t size);


int main() {
	size_t option;
	cout << "1. Selection Sort\n2.Insertion Sort\n";
	cin >> option;
	const size_t ELEMENTS = 7;
	const size_t TESTS = 3;
	int data[][ELEMENTS] = {
			{7, 5, 4, 1, 3, 0, 9},
			{1, 5, 9, 11, 13, 20, 29},
			{8, 5, 4, 1, 3, 4, 0}};


	for (int i = 0; i < TESTS; ++i) {
		PrintArray(data[i], ELEMENTS);
		if (option == 1)
			SelectionSort(data[i], ELEMENTS);
		else if (option == 2)
			InsertionSort(data[i], ELEMENTS);
		PrintArray(data[i], ELEMENTS);
		cout << endl << endl;
	}

	return 0;
}

size_t FindMinimumPosition(const int* data, size_t size){
	int minimumPos= 0;
	for (int i = 1; i < size; ++i) {
		if (data[minimumPos] > data[i])
			minimumPos = i;
	}
	return minimumPos;
}
void Swap(int& a, int& b){
	int t = a;
	a = b;
	b = t;
}
void SelectionSort(int* data, size_t size){
	if (size == 1)
		return;
	else{
		Swap(data[0], data[FindMinimumPosition(data, size)]);
		SelectionSort(data + 1, size - 1);
	}

}
void InsertionSort(int* data, size_t size){
	for (int i = 1; i < size; ++i) {
		int j = i;
		// Insert numbers[i] into sorted part
		// stopping once numbers[i] in correct position
		while (j > 0 && data[j] < data[j - 1]) {
			// Swap numbers[j] and numbers[j - 1]
			Swap(data[j], data[j - 1]);
			--j;
		}
	}
}

void PrintArray(const int* data, size_t size){
	for (int i = 0; i < size; ++i) {
		cout << setw(4) << data[i];
	}
	cout << endl;
}

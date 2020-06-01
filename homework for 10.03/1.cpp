#include<iostream>
#include<ctime>
using namespace std;

void SelectionSort(int ar[], int size) {
	int temp, min;
	for (int i = 0; i < size - 1; i++) {
		min = i;
		for (int j = i + 1; j < size; j++) {
			if (ar[j] < ar[min]) {
				min = j;
			}
		}
		temp = ar[i];
		ar[i] = ar[min];
		ar[min] = temp;
		bool b = true;
		for (int k = 0; k < size - 1; k++) {
			cout << ar[k] << ' ';
			if (ar[k] > ar[k + 1]) b = false;
		}
		cout << ar[size - 1] << ' ';
		cout << endl;
		if (b == true) break;

	}
}

int main() {

	srand(time(NULL));
	int n = 0;
	cout << "input n: ";
	cin >> n;
	int* ar = new int[n];
	for (int i = 0; i < n; i++) {
		ar[i] = rand() % 10;
		cout << ar[i] << ' ';
	}
	cout << endl;
	SelectionSort(ar, n);
	delete[] ar;

	/*int arp[6] = { 4,9,7,6,2,3 };
	for (int i = 0; i < 6; i++) cout << arp[i] << ' ';
	cout << endl;
	SelectionSort(arp, 6);*/


	return 0;
}
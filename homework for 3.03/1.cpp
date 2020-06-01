#include<iostream>
using namespace std;

int main() {

	int n = 0;
	cout << "input n: ";
	cin >> n;
	int* ar1 = new int[n];
	int* ar = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> ar1[i];
	}

	int k = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (ar1[i] != ar1[i - 1]) { ar[k] = ar1[i];  k++; }
	}

	int* arfinal = new int[k];
	for (int i = 0; i < k; i++) {
		arfinal[i] = ar[i];
		cout << arfinal[i] << ' ';
	}

	delete[] arfinal;
	delete[] ar1;
	delete[] ar;
	return 0;
}
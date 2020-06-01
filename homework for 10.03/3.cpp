#include<iostream>
#include<ctime>
using namespace std;


int binarysearch(int ar[], int key, int low, int high) {
	if (high <= low) return (key > ar[low]) ? (low + 1) : (low);
	int m = (high + low) / 2;
	if (key == ar[m]) return m + 1;
	if (key > ar[m]) return binarysearch(ar, key, m + 1, high);
	return binarysearch(ar, key, low, m - 1);
}

void InsertionSort(int ar[], int n) {
	for (int i = 1; i < n; i++) {
		int key = ar[i];
		int j = i - 1;
		int loc = binarysearch(ar, key, 0, j);

		while (j >= loc) {
			ar[j + 1] = ar[j];
			j--;
		}
		ar[loc] = key;

		bool b = true;
		for (int k = 0; k < n - 1; k++) {
			cout << ar[k] << ' ';
			if (ar[k] > ar[k + 1]) b = false;
		}
		cout << ar[n - 1] << ' ';
		cout << endl;
		if (b == true) break;
	}
}

int main() {

	srand(time(NULL));
	int N = 0;
	cout << "input N: ";
	cin >> N;
	int* A = new int[N];
	for (int i = 0; i < N; i++) {
		A[i] = rand() % 10;
		cout << A[i] << ' ';
	}
	cout << endl;
	InsertionSort(A, N);
	delete[] A;

	/*int arp[7] = { 0,1,3,4,2,7,9 };
	for (int i = 0; i < 7; i++) cout << arp[i] << ' ';
	cout << endl;
	InsertionSort(arp, 7);*/


	return 0;
}
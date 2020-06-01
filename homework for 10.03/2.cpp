#include<iostream>
#include<ctime>
using namespace std;

void InsertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
		bool b = true;
		for (int k = 0; k < n - 1; k++) {
			cout << arr[k] << ' ';
			if (arr[k] > arr[k + 1]) b = false;
		}
		cout << arr[n - 1] << ' ';
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
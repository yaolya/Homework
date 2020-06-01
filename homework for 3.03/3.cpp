#include<iostream>
using namespace std;

int main() {

	int n = 0;
	cout << "input n: ";
	cin >> n;
	if (n > 0) {
		int* ar = new int[2 * n];

		for (int i = 0; i < 2 * n; i++) {
			cin >> ar[i];
		}

		for (int i = 0; i < 2 * n - 1; i++) {
			for (int j = 0; j < 2 * n - i - 1; j++) {
				if (ar[j] > ar[j + 1]) {
					int temp = ar[j];
					ar[j] = ar[j + 1];
					ar[j + 1] = temp;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			cout << ar[i] << ' ' << ar[2 * n - i - 1] << endl;
		}

		delete[] ar;
	}
	return 0;
}
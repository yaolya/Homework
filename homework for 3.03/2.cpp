#include<iostream>
#include<cstdlib>
#include<iomanip>
#include<ctime>
using namespace std;

int main() {

	srand(time(NULL));
	int ar[10][10];

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			ar[i][j] = rand() % 1001;
			cout << setw(4) << ar[i][j] << ' ';
		}
		cout << endl;
	}

	int imax = 0;
	int jmax = 0;
	for (int k = 0; k < 10; k++) {
		int max = -1;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (ar[i][j] > max) {
					if (k == 0) {
						max = ar[i][j];
						imax = i;
						jmax = j;
					}
					else {
						if ((i != j) || ((i == j) && (i >= k))) {
							max = ar[i][j];
							imax = i;
							jmax = j;
						}
					}
				}
			}
		}
		int temp = ar[k][k];
		ar[k][k] = max;
		ar[imax][jmax] = temp;
	}
	cout << endl;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << setw(4) << ar[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}
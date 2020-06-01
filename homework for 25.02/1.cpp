#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {

	fstream f;
	f.open("1.txt", ios_base::in);

	if (f.is_open()) {

		double s = 0;
		double a = 0;
		int k = 0;
		while (!f.eof()) {
			f >> a;
			s += a;
			k++;
		}
		cout << fixed << setprecision(2) << (double)s / k << endl;

		f.close();

	}
	else {
		cout << "file is not open" << endl;
	}

	return 0;
}

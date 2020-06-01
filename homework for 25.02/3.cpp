#include <iostream>
#include <fstream>
using namespace std;

int main() {

	fstream f;
	f.open("3.txt");

	if (f.is_open()) {

		while (!f.eof()) {
			char c;
			char line[512] = "";
			if (!f.eof()) c = f.get();
			else exit(1);
			int i = 0;
			while (c != '.' && c != '!' && c != '?') {
				if (c != '\n') line[i] = c;
				else i--;
				if (!f.eof()) c = f.get();
				else exit(1);
				i++;
			}
			if (c == '?') {
				line[i] = c;
				cout << line;
			}
			c = f.get();
			if (c == '!') {
				cout << c << endl;
				f.get();
			}
			else if (c == ' ') cout << endl;
		}

		f.close();

	}
	else {
		cout << "file is not open" << endl;
	}

	return 0;
}

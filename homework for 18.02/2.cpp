#include <iostream>
#include <fstream>
using namespace std;

int main() {

	fstream f;
	f.open("2.txt");

	if (f.is_open()) {

		cout << "file is open" << endl;

		int k = 0;
		char c;
		while (!f.eof()) {
			c = f.get();
			if (k == 0) {
				char buff[512];
				int i = 0;
				while (c != '{') {
					if (f.eof()) exit(0);
					c = f.get();
					buff[i] = c;
					i++;
				}
				buff[i] = '\0';
				int n = 0;
				while (buff[i] != ')') i--;
				while (buff[i] != '\n') {
					n++;
					i--;
				}
				i++;
				char* word = new char[n + 1];
				for (int l = 0; l < n; l++) {
					word[l] = buff[i + l];
				}
				word[n] = '\0';
				if (word[0] != 'c' && word[0] != 's') cout << word << endl;
				delete[] word;

			}
			if (c == '{') k++;
			if (c == '}') k--;
		}

		f.close();
	}
	else { cout << "cannot open file" << endl; }



	return 0;
}
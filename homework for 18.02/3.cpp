#include <iostream>
#include <fstream>
using namespace std;

int dlina(char str[]) {
	int s = 0;
	while (str[s] != '\0') s++;
	return s;
}

int main() {

	fstream f;
	f.open("3.txt");

	if (f.is_open()) {

		cout << "file is open" << endl;

		char c = f.get();
		int k = 0;
		int maxlen = 0;
		char* maxword = new char[maxlen + 1];
		while (!f.eof()) {
			int n = 2;
			char* word = new char[n];
			word[0] = c;
			word[1] = '\0';
			if (f.eof()) break;
			c = f.get();
			while (c != ' ' && c != '\n' && (!f.eof())) {
				char* t = new char[n];
				for (int i = 0; i < n; i++) {
					t[i] = word[i];
				}
				n++;
				word = new char[n];
				for (int i = 0; i < n - 2; i++) {
					word[i] = t[i];
				}
				delete[] t;
				word[n - 2] = c;
				word[n - 1] = '\0';
				if (f.eof()) break;
				c = f.get();
			}
			int y = 0;
			if (dlina(word) == maxlen) {
				for (int i = 0; i < maxlen; i++) {
					if (maxword[i] == word[i]) y++;
				}
				if (y == maxlen) k++;
			}
			if (dlina(word) > maxlen) {
				k = 1;
				maxlen = dlina(word);
				maxword = new char[maxlen + 1];
				for (int i = 0; i < maxlen; i++) {
					maxword[i] = word[i];
				}
				maxword[maxlen] = '\0';
			}
			delete[] word;
			if (f.eof()) break;
			c = f.get();
		}
		cout << maxword << ' ' << k;
		delete[] maxword;
		f.close();
	}
	else { cout << "cannot open file" << endl; }


	return 0;
}
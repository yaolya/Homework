#include <iostream>
#include <fstream>
using namespace std;

int strlen(char str[]) {
	int s = 0;
	while (str[s] != '\0') {
		s++;
	}
	return s;
}

bool wordsaresimilar(char initword[], char word[], int s) {
	bool b = true;
	for (int i = 0; i < s; i++) {
		if (initword[i] != word[i]) b = false;
	}
	return b;
}

int main() {

	fstream f;
	f.open("2.txt", ios_base::in);

	if (f.is_open()) {

		char line[512] = "";
		char initword[256] = "";
		cout << "input a word: ";
		cin.getline(initword, 256);

		while (!f.eof()) {
			f.getline(line, 512);
			int i = 0;
			while (line[i] != '\0') {
				int k = 0;
				char word[256] = "";
				while (line[i] != ' ' && line[i] != '\0') {
					word[k] = line[i];
					i++;
					k++;
				}
				i++;
				if (strlen(initword) == strlen(word)) {
					if (wordsaresimilar(initword, word, strlen(word)) == true) { cout << line << endl; break; }
				}
			}
		}

		f.close();

	}
	else {
		cout << "file is not open" << endl;
	}

	return 0;
}

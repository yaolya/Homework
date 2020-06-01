#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argV[]) {

	if (argc >= 1) {

		fstream f;
		string str = "";
		if (argc == 2) str = argV[1];
		if (argc == 1) {
			char buff[6];
			cin.getline(buff, 6);
			str = buff;
		}
		f.open(str);
		int n;
		cin >> n;

		if (f.is_open()) {

			cout << "file is open" << endl;
			int k = 0;
			char c;
			while (!f.eof()) {
				f.get(c);
				if (c == '\n') k++;
			}
			f.clear();
			f.seekg(0);
			int u = 0;
			while (!f.eof()) {
				f.get(c);
				if (c == '\n') u++;
				if (u >= (k - n + 1)) {
					if (c != '\n') cout << c;
					int i = 0;
					char buff[256];
					f.getline(buff, 256);
					while (buff[i] != '\0') {
						cout << buff[i];
						i++;
					}
					cout << endl;
				}
			}
			f.close();
		}
		else { cout << "cannot open file" << endl; }
	}
	else { cout << "incorrect number of arguments" << endl; }

	return 0;
}
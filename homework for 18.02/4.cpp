#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argV[]) {

	if (argc == 3) {

		//char u = '«';
		//char v = '»';
		fstream f1;
		fstream f2;
		f1.open(argV[1]); //"4.txt"
		f2.open(argV[2], ios_base::out); //"output.txt"

		if (f1.is_open() && f2.is_open()) {

			cout << "files are open" << endl;

			char c;
			bool b = false;
			while (!f1.eof()) {
				c = f1.get();
				if (c == 'Â') c = f1.get();
				if (f1.eof()) break;
				if ((int)c != -85 && (int)c != -69) f2.put(c);
				if ((int)c == -85 && !b) {
					f2.put('<');
					f2.put('<');
				}
				if ((int)c == -69 && !b) {
					f2.put('>');
					f2.put('>');
				}
				if (b) f2.put(c);
				if ((int)c == 92) b = true;
				else b = false;
			}

			f1.close();
			f2.close();
		}
		else { cout << "cannot open files" << endl; }
	}
	else { cout << "incorrect number of arguments" << endl; }


	return 0;
}
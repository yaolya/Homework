#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <ctime>
#include <cstdlib>
#include <Windows.h>

struct Letter {
	char c;
	int number;
	int price;
};

Letter LetByNum(int index, std::vector<Letter>& alph) {
	int s = 0;
	int i = 0;
	while (s < index) {
		s += alph[i].number;
		++i;
	}
	if (s == index) {
		if (alph[i].number > 0) {
			--alph[i].number;
			return alph[i];
		}
		else {
			while (alph[i].number == 0)
				if (i < alph.size()) i++;
				else i = 0;
			--alph[i].number;
			return alph[i];
		}
	}
	else {
		--i;
		if (alph[i].number > 0) {
			alph[i].number--;
			return alph[i];
		}
		else {
			while (alph[i].number == 0)
				if (i < alph.size()) i++;
				else i = 0;
			--alph[i].number;
			return alph[i];
		}
	}
}

char inputLet() {
	char eigth;
	std::cout << "Введите букву, которая обязательно должна присутствовать в слове: ";
	std::cin >> eigth;
	return eigth;
}

void getLetter(Letter* arr, std::vector<Letter>& alph) {
	bool b = false;
	while (!b) {
		int k = 0;
		char eigth = inputLet();
		while (k < alph.size() && alph[k].c != eigth) k++;
		if (k >= alph.size()) std::cout << "Такой буквы нет в наборе" << std::endl;
		else if (alph[k].number == 0) std::cout << "Фишки с этой буквой закончились, введите другую букву" << std::endl;
		else { arr[7] = alph[k]; b = true; }
	}
}

void Initialize(Letter* array, std::vector<Letter>& al) {
	int numoff = 131;
	for (int i = 0; i < 7; ++i) {
		array[i] = LetByNum(rand() % numoff, al);
		--numoff;
	}
	getLetter(array, al);
	for (int i = 0; i < 8; i++) {
		std::cout << array[i].c << ' ';
	}
	std::cout << std::endl;
}

int price(char* buffer, Letter* arr, int len) {
	int pr = 0;
	char* buff = new char[len + 1];
	for (int i = 0; i < len; i++) {
		buff[i] = buffer[i];
	}
	buff[len] = '\0';
	for (int k = 0; k < 8; k++) {
		int i = 0;
		while (buff[i] != '\0' && buff[i] != arr[k].c) i++;
		if (buff[i] == arr[k].c) {
			pr += arr[k].price;
			buff[i] = 'ё';
		}
	}
	delete[] buff;
	return pr;
}

int Zv(Letter* arr) {
	int z = 0;
	for (int i = 0; i < 8; i++) {
		if (arr[i].c == '*') z++;
	}
	return z;
}

int main() {

	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(time(NULL));

	std::vector<Letter> alphabet{ {'а',10,1}, {'б',3,3}, {'в',5,2}, {'г',3,3}, {'д',5,2}, {'е',9,1}, {'ж',2,5}, {'з',2,5}, {'и',8,1},
	{'й',4,2}, {'к',6,2}, {'л',4,2}, {'м',5,2}, {'н',8,1},  {'о',10,1},  {'п',6,2},  {'р',6,2},  {'с',6,2},  {'т',5,2},  {'у',3,3},
	{'ф',1,10}, {'х',2,5}, {'ц',1,10}, {'ч',2,5},  {'ш',1,10},  {'щ',1,10},  {'ъ',1,10},  {'ы',2,5},  {'ь',2,5},  {'э',1,10},  {'ю',1,10},
	{'я',3,3}, {'*',3,0} };

	Letter ar[8];
	Initialize(ar, alphabet);
	int num_of_zv = Zv(ar);

	std::fstream f;
	f.open("dictionary.txt", std::ios_base::in);
	if (f.is_open()) {
		std::cout << "File is open " << std::endl;
		char buf[128] = "";
		char buffin[128];
		char max_word[128] = "такого слова нет";
		int max_price = 0;
		std::vector<int> vec;
		while (!f.eof()) {
			f.getline(buf, 128);
			bool req_letter = false;
			int s = 0;
			while (buf[s] != '\0') {
				buffin[s] = buf[s];
				s++;
			}
			buffin[s] = '\0';
			int count = 0;
			for (int i = 0; i < s; i++) {
				if (buf[i] == ar[7].c) req_letter = true;
			}
			for (int k = 0; k < 7; ++k) {
				int i = 0;
				while (i < s && buf[i] != ar[k].c) {
					i++;
				}
				if (buf[i] == ar[k].c) {
					buf[i] = 'ё';
					++count;
				}
			}
			if (count + num_of_zv >= s) {
				if (price(buffin, ar, s) > max_price&& req_letter) {
					for (int k = 0; k < s; k++) {
						max_word[k] = buffin[k];
					}
					max_word[s] = '\0';
					max_price = price(buffin, ar, s);
				}
			}
		}
		std::cout << "Слово с наибольшей ценой (" << max_price << "): " << max_word << std::endl;
		f.close();
	}
	else std::cout << "Cannot open file " << std::endl;

	return 0;
}
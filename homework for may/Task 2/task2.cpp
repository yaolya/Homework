#include <iostream>
#include <ctime>
#include <cstdlib>

void compare(int input, int generated) {
	if (input > generated) std::cout << "Введённое число больше загаданного" << std::endl;
	if (input < generated) std::cout << "Загаданное число больше введённого" << std::endl;
	if (input == generated) {
		std::cout << "Успех" << std::endl;
		exit(0);
	}
}

int main() {

	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	int n = 7;
	std::cout << "У вас есть " << n << " попыток, чтобы угадать число" << std::endl;
	int a = rand() % 101;
	int m = 0;

	for (int i = 0; i < n; ++i) {
		std::cout << "Попытка №" << i + 1 << ": ";
		std::cin >> m;
		if (m < 0 || m > 100) std::cout << "Загадано число из диапазона [0,100]" << std::endl;
		compare(m, a);
	}
	std::cout << "Проигрыш" << std::endl;

	return 0;
}
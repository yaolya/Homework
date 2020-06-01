#include <iostream>

int numofdiv(int a) {
	int num = 2;
	for (int k = 2; k < abs(a); ++k) {
		if (a % k == 0) ++num;
	}
	return num;
}

int maxNumOfDiv(int m, int n) {
	int max = 0;
	int maxNum = 0;
	for (int k = m; k <= n; ++k) {
		if (numofdiv(k) > max) {
			max = numofdiv(k);
			maxNum = k;
		}
	}
	return maxNum;
}

int main() {

	setlocale(LC_ALL, "ru");
	int M = 0;
	int N = 0;
	std::cout << "Введите М: ";
	std::cin >> M;
	std::cout << "Введите N: ";
	std::cin >> N;
	if (M > N) {
		std::cout << "Интервал задан неверно" << std::endl;
		exit(1);
	}

	std::cout << "Число, имеющее наибольшее количество делителей на промежутке [" << M << "," << N << "]: " << maxNumOfDiv(M, N) << std::endl;

	return 0;
}
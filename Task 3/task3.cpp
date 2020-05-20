#include <iostream>
#include <vector>

bool f(std::vector<int>& v, int index, int s, int half, int count) {
	if (count >= v.size() / 2) { return false; }
	for (int i = index; i < v.size(); ++i) {
		if (s + v[i] == half) { std::cout << "YES" << std::endl; exit(0); }
		else f(v, index + 1, s + v[i], half, count + 1);
	}
	return false;
}

bool divide(std::vector<int>& vec) {
	int k = 0;
	int c = 0;
	for (int i = 0; i < vec.size(); ++i) {
		k += vec[i];
	}
	if (k % 2 != 0) return false;
	return f(vec, 0, 0, k / 2, c);
}

int main() {

	setlocale(LC_ALL, "ru");

	int num = 0;
	std::cout << "Введите количество камней: ";
	std::cin >> num;
	if (num >= 10 || num < 0) {
		std::cout << "Количество камней должно быть больше 0 и меньше 10" << std::endl;
		exit(1);
	}
	std::vector<int> vector(num);
	std::cout << "Введите массы камней: ";
	for (int i = 0; i < vector.size(); ++i) {
		std::cin >> vector[i];
		if (vector[i] >= 10000 || vector[i] < 0) {
			std::cout << "Масса камня должна быть < 10000" << std::endl;
			exit(1);
		}
	}

	std::cout << (divide(vector) ? "YES" : "NO") << std::endl;

	return 0;
}
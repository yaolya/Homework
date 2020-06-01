#include <iostream>
#include <ctime>
#include <cstdlib>

void compare(int input, int generated) {
	if (input > generated) std::cout << "�������� ����� ������ �����������" << std::endl;
	if (input < generated) std::cout << "���������� ����� ������ ���������" << std::endl;
	if (input == generated) {
		std::cout << "�����" << std::endl;
		exit(0);
	}
}

int main() {

	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	int n = 7;
	std::cout << "� ��� ���� " << n << " �������, ����� ������� �����" << std::endl;
	int a = rand() % 101;
	int m = 0;

	for (int i = 0; i < n; ++i) {
		std::cout << "������� �" << i + 1 << ": ";
		std::cin >> m;
		if (m < 0 || m > 100) std::cout << "�������� ����� �� ��������� [0,100]" << std::endl;
		compare(m, a);
	}
	std::cout << "��������" << std::endl;

	return 0;
}
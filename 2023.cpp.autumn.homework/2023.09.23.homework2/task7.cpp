#include <iostream>

int main(int argc, int argv[]) {
	int n = 0;
	std::cin >> n;
	if (n / 50 > 0) {
		std::cout << "L";
	}
	if ((n % 50) / 10 == 1) {
		std::cout << "X";
	}
	if ((n % 50) / 10 == 2) {
		std::cout << "XX";
	}
	if ((n % 50) / 10 == 3) {
		std::cout << "XXX";
	}
	if ((n % 50) / 10 == 4) {
		std::cout << "XXXX";
	}
	if (n % 10 == 6) {
		std::cout << "VI";
	}
	if (n % 10 == 7) {
		std::cout << "VII";
	}
	if (n % 10 == 8) {
		std::cout << "VIII";
	}
	if (n % 10 == 9) {
		std::cout << "IX";
	}
	if (n % 10 == 5) {
		std::cout << "V";
	}
	if (n % 10 == 1) {
		std::cout << "I";
	}
	if (n % 10 == 2) {
		std::cout << "II";
	}
	if (n % 10 == 3) {
		std::cout << "III";
	}
	if (n % 10 == 4) {
		std::cout << "IV";
	}
	return EXIT_SUCCESS;
}
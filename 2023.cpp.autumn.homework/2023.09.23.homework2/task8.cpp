#include <iostream>

int main(int argc, char* argv[]) {
	int a = 0;
	int b = 0;
	int c = 0;
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	if (a >= b >= c) {
		std::cout << c << " " << b << " " << a;
	}
	else if (a >= c >= b) {
		std::cout << b << " " << c << " " << a;
	}
	else if (b >= c >= a) {
		std::cout << a << " " << c << " " << b;
	}
	else if (b >= a >= c) {
		std::cout << c << " " << a << " " << b;
	}
	else if (c >= a >= b) {
		std::cout << b << " " << a << " " << c;
	}
	else if (c >= b >= a) {
		std::cout << a << " " << b << " " << c;
	}
	return EXIT_SUCCESS;
}
#include <iostream>

int main(int argc, char* argv[]) {
	int a = 0;
	int b = 0;
	std::cin >> a;
	std::cin >> b;
	while (a > b) {
		if (a % 2 == 0 && a / b > 1) {
			a = a / 2;
			std::cout << ":2" << std::endl;
		}
		else {
			a -= 1;
			std::cout << "-1" << std::endl;
		}
	}
	return EXIT_SUCCESS;
}
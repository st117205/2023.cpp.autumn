#include <iostream>

int main(int argc, char* argv[]) {
	int n = 0;
	std::cin >> n;
		if ((n % 100) > 10 && (n % 100 < 20)) {
			std::cout << n << " bochek";
		}
		else {
			if (n % 10 == 1) {
				std::cout << n << " bochka";
			}
			if (n % 10 == 2 || n % 10 == 3 || n % 10 == 4) {
				std::cout << n << " bochki";
			}
			if (n % 10 == 0 || n % 10 == 5 || n % 10 == 6 || n % 10 == 7 || n % 10 == 8 || n % 10 == 9) {
				std::cout << n << " bochek";
			}
		}
	return EXIT_SUCCESS;
} 
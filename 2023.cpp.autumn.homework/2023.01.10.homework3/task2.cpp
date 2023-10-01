#include <iostream>

int main(int argc, char* argv[]) {
	long long n = 0;
	std::cin >> n;
	while (n % 10 == 0) {
		n = n / 10;
	}
	while (n > 0) {
		std::cout << n % 10;
		n = n / 10;
	}
	return EXIT_SUCCESS;
}
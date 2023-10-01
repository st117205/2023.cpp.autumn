#include <iostream>

int main(int argc, char* argv[]) {
	long long x = 0;
	int k = 0;
	std::cin >> x;
	for (int i = 1; i * i <= x + 1; i += 1) {
		if (x % i == 0) {
			if (i * i == x) {
				k += 1;
			}
			else {
				k += 2;
			}
		}
	}
	std::cout << k;
	return EXIT_SUCCESS;
}
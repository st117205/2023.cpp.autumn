#include <iostream>

int main(int argc, char* argv[]) {
	int n = 0;
	int num = 2;
	int extent = 1;
	std::cin >> n;
	for (int k = 1; k <= 100; k++) {
		while (k > 1) {
			num *= 2;
			k -= 1;
			extent += 1;
		}
		if (n == 1) {
			std::cout << 0;
			break;
		}
		if (num >= n) {
			std::cout << extent;
			break;
		}

	}
	return EXIT_SUCCESS;
}
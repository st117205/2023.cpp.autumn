#include <iostream>

int main(int atgc, char* argv[]) {
	int k = 0;
	int m = 0;
	int n = 0;
	int p = 0;
	std::cin >> k;
	std::cin >> m;
	std::cin >> n;
	if (n % k == 0) {
		p = n / k;
	}
	else {
		p = n / k + 1;
	}
	std::cout << 2 * m * p;
	return EXIT_SUCCESS;
}

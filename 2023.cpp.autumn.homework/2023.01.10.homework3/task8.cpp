#include <iostream>

int main(int argc, char* argv[]) {
	int a = 0;
	int b = 0;
	int n = 0;
	std::cin >> a;
	std::cin >> b;
	std::cin >> n;
	if ((n < a < b) and (a - b % a) == n) {
		int k = b / a + 1;
		while (k > 0) {
			std::cout << ">A" << std::endl;
			std::cout << "A>B" << std::endl;
			k -= 1;
		}
	}
	if ((n < b < a) and (b - a % b) == n) {
		int k = a / b + 1;
		while (k > 0) {
			std::cout << ">B" << std::endl;
			std::cout << "B>A" << std::endl;
			k -= 1;
		}
	}
	if ((n > a or n > b) or (a % b == 0 and a != b and a != n) or (a != b and a != n and b % a == 0)) {
		std::cout << "Impossible";
	}
	if (n == a) {
		std::cout << ">A";
	}
	if (a != n and n == b) {
		std::cout << ">B";
	}
	return EXIT_SUCCESS;
}
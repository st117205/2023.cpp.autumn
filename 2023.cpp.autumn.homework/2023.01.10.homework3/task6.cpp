#include <iostream>

int main(int argc, char* argv[]) {
	long long n = 0;
	long long n1 = 1;
	long long n2 = 1;
	long long next = 0;
	std::cin >> n;
	if (n > 2) {
		while (n > 2) {
			next = n1 + n2;
			n1 = n2;
			n2 = next;
			n -= 1;
		}
		std::cout << next;
	}
	else {
		std::cout << 1;
	}
	return EXIT_SUCCESS;
}
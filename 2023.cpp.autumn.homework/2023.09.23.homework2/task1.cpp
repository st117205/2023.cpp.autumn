#include <iostream>

int main(int argc, char* argv[]) {
	int n = 0;
	std::cin >> n;
	if ((n % 4 == 0 and n % 100 != 0) or n % 400 == 0) {
		std::cout << "YES";
	}
	else {
		std::cout << "NO";
	}
	return EXIT_SUCCESS;
}
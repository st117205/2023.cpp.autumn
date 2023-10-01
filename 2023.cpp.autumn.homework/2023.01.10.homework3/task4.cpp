#include <iostream>

int main(int argc, char* argv[]) {
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	std::cin >> d;
	for (int x = 0; x <= 1000; x += 1) {
		if ((a * x * x * x + b * x * x + c * x + d) == 0) {
			std::cout << x << " ";
		}
	}
	return EXIT_SUCCESS;
}
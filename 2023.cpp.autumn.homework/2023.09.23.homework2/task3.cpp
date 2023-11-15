#include <iostream>
#include <math.h>

int main(int argc, char* argv[]) {
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	std::cin >> a;
	std::cin >> b;
	std::cin >> c;
	std::cin >> d;
	if (a == 0 && b == 0) {
		std::cout << "INF";
	}
	else if ((a != 0 && b != 0 && abs(b) % abs(a) == 0 && abs(d) % abs(c) == 0 && -b / a != -d / c) || (a != 0 && b != 0 && abs(b) % abs(a) == 0 && abs(d) % abs(c) != 0) || (a != 0 && b == 0)) {
		std::cout << -b / a;
	}
	else {
		std::cout << "NO";
	}
	return EXIT_SUCCESS;
}
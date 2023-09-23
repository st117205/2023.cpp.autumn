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
	if (a == 0 and b == 0) {
		std::cout << "INF";
	}
	else if ((a != 0 and b != 0 and abs(b) % abs(a) == 0 and abs(d) % abs(c) == 0 and -b / a != -d / c) or (a != 0 and b != 0 and abs(b) % abs(a) == 0 and abs(d) % abs(c) != 0) or (a != 0 and b == 0)) {
		std::cout << -b / a;
	}
	else {
		std::cout << "NO";
	}
	return EXIT_SUCCESS;
}
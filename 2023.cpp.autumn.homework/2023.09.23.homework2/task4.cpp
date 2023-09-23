#include <iostream>

int main(int argc, char* argv[]) {
	int n = 0;
	int x1 = 0;
	int x5 = 0;
	int x10 = 0;
	int x20 = 0;
	int x60 = 0;
	std::cin >> n;
	if (n / 60 >= 1) {
		x60 = n / 60;
		n = n % 60;
	}
	if (n > 35) {
		x60 += 1;
	}
	else {
		x20 = n / 20;
		n = n % 20;
		if (n > 17) {
			x20 += 1;
		}
		else {
			x10 = n / 10;
			n = n % 10;
			if (n != 9) {
				x5 = n / 5;
				n = n % 5;
				x1 = n;
			}
			else {
				x10 += 1;
			}
		}
	}
	std::cout << x1 << " " << x5 << " " << x10 << " " << x20 << " " << x60;
	return EXIT_SUCCESS;
}

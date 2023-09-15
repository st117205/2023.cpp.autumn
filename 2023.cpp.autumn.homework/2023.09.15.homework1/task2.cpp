#include <iostream>

int main() {
	int a;
	std::cin >> a;
	int b;
	std::cin >> b
	std::cout << (a >= b) * a + (b > a) * b;
	return 0;
}
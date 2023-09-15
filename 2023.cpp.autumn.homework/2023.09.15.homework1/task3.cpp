#include <iostream>

int main() {
	long long n;
	std::cin >> n;
	std::cout << ((n / 10) * (n / 10 + 1)) * 100 + 25;
	return 0;
}
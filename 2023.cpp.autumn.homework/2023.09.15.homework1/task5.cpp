﻿#include <iostream>

int main(int argc, char* argv[]) {
	int v = 0;
	int t = 0;
	std::cin >> v;
	std::cin >> t
	std::cout << ((v * t) % 109 + 109 * 10) % 109 + 1;
	return EXIT_SUCCESS;
}
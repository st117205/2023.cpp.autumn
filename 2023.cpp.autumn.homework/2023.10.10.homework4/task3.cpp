#include <iostream>
#include <cstdlib>

int main(int, char**) {
	int n = 0;
	int c = 0;
	std::cin >> n;
	int* a = (int*)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; ++i) {
		std::cin >> c;
		*(a + i) = c;
	}
	for (int i = 0; i < n; ++i) {
		if (*(a + i) % 2 == 1) {
			std::cout << *(a + i);
		}
	}
	free(a);
	return EXIT_SUCCESS;
}

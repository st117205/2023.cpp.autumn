#include <iostream>
#include <cstdlib>

int main(int, char**) {
	int n = 0;
	int c = 0;
	int m = 0;
	std::cin >> n;
	int* a = (int*)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; ++i) {
		std::cin >> c;
		*(a + i) = c;
	}
	for (int i = 0; i < n; ++i) {
		if (*(a + i) > m) {
			m = *(a + i);
		}
	}
	std::cout << m;
	free(a);
	return EXIT_SUCCESS;
}

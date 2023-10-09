#include <iostream>
#include <cstdlib>

int main(int, char**) {
	int n = 0;
	int c = 0;
	int mx = 0;
	int mn = 1000000000;
	int flagmn = 0;
	int flagmx = 0;
	std::cin >> n;
	int* a = (int*)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; ++i) {
		std::cin >> c;
		*(a + i) = c;
	}
	for (int i = 0; i < n; ++i) {
		if (*(a + i) > mx) {
			mx = *(a + i);
		}
	}
	for (int i = 0; i < n; ++i) {
		if (*(a + i) < mn) {
			mn = *(a + i);
		}
	}
	for (int i = 0; i < n; ++i) {
		if (*(a + i) == mn and flagmn == 0) {
			*(a + i) = mx;
			flagmn += 1;
		}
	}
	for (int i = n - 1; i >= 0; --i) {
		if (*(a + i) == mx and flagmx == 0) {
			*(a + i) = mn;
			flagmx += 1;
		}
	}
	for (int i = 0; i < n; ++i) {
		std::cout << *(a + i) << " ";
	}
	free(a);
	return EXIT_SUCCESS;
}


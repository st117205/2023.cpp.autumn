#include <iostream>

int main(int argc, char* argv[]) {
	int n = 0;
	int num = 1;
	int curr = 1;
	std::cin >> n;
	while (n > 0) {
		if (curr > 1) {
			std::cout << num << " ";
			curr -= 1;
		}
		else {
			std::cout << num << " ";
			num += 1;
			curr = num;
		}
		n -= 1;
	}
	return EXIT_SUCCESS;
}
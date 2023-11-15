#include <iostream>

int main(int argc, char* argv[]) {
	int answer = 0;
	int student = 0;
	std::cin >> answer;
	std::cin >> student;
	if ((answer == 1 && student == 1) || (answer != 1 && student != 1)) {
		std::cout << "YES";
	}
	else {
		std::cout << "NO";
	}
	return EXIT_SUCCESS;
}
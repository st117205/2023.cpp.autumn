#include <iostream>

int main(int, char**)
{
	int n = 0;
	std::cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			std::cout << 2*n - j - 1 << " ";
		}
		std::cout << std::endl;
	}
	return EXIT_SUCCESS;
}
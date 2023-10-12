#include <iostream>

int main(int, char**)
{
	int n = 0;
	std::cin >> n;
	for (int i = 0; i < n; ++i)
	{
		if (i % 2 == 1)
		{
			for (int j = 0; j < n; ++j)
			{
				std::cout << j + 1 << " ";
			}
			std::cout << std::endl;
		}
		else
		{
			for (int j = n; j > 0; --j)
			{
				std::cout << j << " ";
			}
			std::cout << std::endl;
		}
	}
	return EXIT_SUCCESS;
}
#include <iostream>

int main(int, char**)
{
	int n = 0;
	std::cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int count = 0;
		while (count < n)
		{
			std::cout << i + 1 << " ";
			count += 1;
		}
		std::cout << std::endl;
	}
	return EXIT_SUCCESS;
}
#include <iostream>
#include <stdlib.h>
#include <string>

void printArray(int* a, int len);
void addElement(int*& a, int& len, int element);
void expandArray(int*& a, int& len);
void contractArray(int*& a, int& len, int index);
void sortArray(int*& a, int& len);
int minArray(int*& a, int& len);
int indexElement(int a, int len, int element);
void reverseArray(int*& a, int& len);
void swapArray(int*& a, int& len);
int firstmaxArray(int*& a, int& len);
int lastminArray(int*& a, int& len);
void setArray(int* a, int len);
void addrandomElements(int*& a, int& len);
void printMenu();


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	int* a = nullptr;
	int len = 0;
	bool exit = false;
	while (!exit)
	{
		{
			system("cls");
			printMenu();
			printArray(a, len);
		}
		int choice = 0;
		{
			std::cin >> choice;
		}
		{
			switch (choice)
			{
			case 0:
			{
				exit = true;
				break;
			}
			case 1:
			{
				printArray(a, len);
				break;
				system("pause");
			}
			case 2:
			{
				int element = 0;
				std::cout << "Введите элемент для добавления" << std::endl;
				std::cin >> element;
				addElement(a, len, element);
				break;
			}
			case 3:
			{
				int index = 0;
				std::cout << "Введите индекс элемента для удаления" << std::endl;
				std::cin >> index;
				contractArray(a, len, index);
				break;
			}
			case 4:
			{
				sortArray(a, len);
				break;
			}
			case 5:
			{
				reverseArray(a, len);
				break;
			}
			case 6:
			{
				swapArray(a, len);
				break;
			}
			case 7:
			{
				setArray(a, len);
				break;
			}
			case 8:
			{
				std::cout << "Введите количество случайных чисел" << std::endl;
				addrandomElements(a, len);
				break;
			}
			default:
				std::cout << "Неизвестная команда" << std::endl;
				break;
			}
		}
	}
	return EXIT_SUCCESS;
}

void printArray(int* a, int len)
{
	if (a == nullptr)
	{
		std::cout << "EMPTY";
	}
	else
	{
		for (int i = 0; i < len; ++i)
		{
			std::cout << a[i] << " ";
		}
		std::cout << std::endl;
	}
}

void expandArray(int*& a, int& len)
{
	int* newA = new int[len + 1] {0};
	if (a != nullptr)
	{
		for (int i = 0; i < len; ++i)
		{
			newA[i] = a[i];
		}
		delete[] a;
	}
	a = newA;
	++len;
}

void addElement(int*& a, int& len, int element)
{
	expandArray(a, len);
	a[len - 1] = element;
}

void contractArray(int*& a, int& len, int index)
{
	if (a != nullptr)
	{
		int* newA = new int[len - 1] {0};
		for (int i = 0; i < len - 1; ++i)
		{
			if (i != index)
			{
				newA[i] = a[i];
			}
		}
		delete[] a;
		a = newA;
		--len;
	}
}

int minArray(int*& a, int& len)
{
	int mn = 100000000;
	for(int i = 0; i < len; ++i)
	{
		if (a[i] < mn)
		{
			mn = a[i];
		}
	}
	return mn;
}

int indexElement(int a, int len, int element)
{
	if (a != nullptr)
	{
		for (int i = 0; i < len; ++i)
		{
			if (a[i] == element)
			{
				return i;
			}
		}
	}
}

void sortArray(int*& a, int& len)
{
	if (a != nullptr)
	{
		int* newA = new int[len] {0};
		for (int i = 0; i < len; ++i)
		{
			int mnArray = minArray(a, len);
			newA[i] = mnArray;
			int idElement = indexElement(a, len, mnArray);
			contractArray(a, len, idElement);
		}
		delete[] a;
		a = newA;
	}
}

void reverseArray(int*& a, int& len)
{
	if (a != nullptr)
	{
		int* newA = new int[len] {0};
		for (int i = 0; i < len; ++i)
		{
			int k = 1;
			for (int j = len - k; j >= 0; --j)
			{
				newA[i] = a[j];
				break;
			}
			++k;
		}
		delete[] a;
		a = newA;
	}
}

int firstmaxArray(int*& a, int& len)
{
	if (a != nullptr)
	{
		int m = -10000000;
		for (int i = 0; i < len; ++i)
		{
			if (a[i] > m)
			{
				m = a[i];
			}
		}
		return m;
	}
}

void swapArray(int*& a, int& len)
{
	if (a != nullptr)
	{
		int* newA = new int[len] {0};
		int firstmxArray = firstmaxArray(a, len);
		int lastmnArray = lastminArray(a, len);
		int idfirstmxElement = indexElement(a, len, firstmxArray);
		int idlastmnElement = indexElement(a, len, lastmnArray);
		for (int i = 0; i < len; ++i)
		{
			if (i != idlastmnElement && i != idfirstmxElement)
			{
				newA[i] = a[i];
			}
			if (i == idlastmnElement)
			{
				newA[i] = a[idfirstmxElement];
			}
			else
			{
				newA[i] = a[idlastmnElement];
			}
		}
		delete[] a;
		a = newA;
	}
}

void setArray(int* a, int len)
{
	if (a != nullptr)
	{
		for (int i = 0; i < len; ++i)
		{
			for (int j = 0; j < len; ++j)
			{
				if (a[i] == a[j + 1])
				{
					int idElement = indexElement(a, len, a[j + 1]);
					contractArray(a, len, idElement);
				}
			}
		}
	}
}

void addrandomElements(int*& a, int& len)
{
	srand(time(NULL));
	int n = 0;
	std::cin >> n;
	for (int i = 0; i < n; ++i)
	{
		expandArray(a, len);
	}
	for (int i = len; i < len + n; ++i)
	{
		a[i] = rand();
	}
}

void printMenu()
{
	std::cout << "0 - Выход из программы" << std::endl;
	std::cout << "1 - Вывести массив" << std::endl;
	std::cout << "2 - Добавить элемент в массив" << std::endl;
	std::cout << "3 - Удалить элемент из массива" << std::endl;
	std::cout << "4 - Отсортировать массив по возрастанию" << std::endl;
	std::cout << "5 - Развернуть массив" << std::endl;
	std::cout << "6 - Поменять местами первый максимальный и последний минимальный элементы массива" << std::endl;
	std::cout << "7 - Удалить из массива все дубликаты" << std::endl;
	std::cout << "8 - Добавить в массив n случайных элементов" << std::endl;
}

int lastminArray(int*& a, int& len)
{
	int mn = 100000000;
	for (int i = 0; i < len; ++i)
	{
		if (a[i] <= mn)
		{
			mn = a[i];
		}
	}
	return mn;
}
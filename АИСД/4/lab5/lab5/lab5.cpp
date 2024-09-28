#include <Windows.h>
#include <iostream>
#include <algorithm>
using namespace std;

void func(int* ptr, size_t size)
{
	std::sort(ptr, ptr + size);
	int maxSum = 0;
	for (size_t i = 0; i < size / 2; i++)
	{
		printf_s("%d %d ", ptr[size - 1 - i], ptr[i]);
		maxSum += ptr[size - i - 1];
	}
	if (size % 2 == 1)
	{
		cout << ptr[size / 2];
		maxSum += ptr[size / 2];
	}
	cout << "\n\n" << maxSum;
}

int main() {
	SetConsoleOutputCP(1251);
	int size = 5;
	int* array = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		array[i] = rand() % 100 + 1;
		cout << array[i] << ' ';
	}
	cout << "\n";
	func(array, size);
	return 0;
}

#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

void func(int* ptr, int size)
{
	std::sort(ptr, ptr + size, [&](int x, int y) {return x > y; });

	std::for_each(ptr, ptr + size, [&](int x) {cout << x << " "; });

	std::set<int> unique(ptr, ptr + size);
	std::set<int>::iterator it = (unique.size() > 4) ? std::prev(unique.end(), 4) : unique.begin();

	cout << "\n" << std::distance(ptr, std::find(ptr, ptr + size, *it));
}
int main() {

	int size;
	scanf_s("%d", &size);
	int* array = new int[size];
	srand(time(NULL));
	for (size_t i = 0; i < size; i++)
	{
		array[i] = rand() % 100 + 1;
		cout << array[i] << ' ';
	}
	cout << "\n";
	func(array, size);
	return 0;
}

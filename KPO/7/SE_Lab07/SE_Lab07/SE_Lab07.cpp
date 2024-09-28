#include <Windows.h>
#include <iostream>
#include "Call.h"
using namespace std;

int main() {
	SetConsoleOutputCP(1251);
	int a = 12, b = 23, c = 34, d = 1243;
	cout << Call::cdekl(a, b, c) << '\n';
	cout << Call::cstd(a, b, c) << '\n';
	cout << Call::cfst(a, b, c, d) << '\n';
	return 0;
}

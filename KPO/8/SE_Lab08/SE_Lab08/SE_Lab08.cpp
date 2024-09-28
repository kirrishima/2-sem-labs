#include <iostream>
using namespace std;

int defaultparm(int a, int b, int c, int d, int e, int f = 0, int g = 999)
{
	return (a + b + c + d + e + f + g);
}
int main() {

	defaultparm(1, 2, 3, 4, 5);
	defaultparm(1, 2, 3, 4, 5, 6, 7);

	return 0;
}

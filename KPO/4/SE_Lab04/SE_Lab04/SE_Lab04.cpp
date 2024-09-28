#include <Windows.h>
#include <iostream>
using namespace std;

typedef unsigned char day;
typedef unsigned char month;
typedef unsigned short year;

struct Date
{
	day dd;
	month mm;
	year yyyy;
	Date(day dd, month mm, year yyyy)
	{
		this->dd = dd;
		this->mm = mm;
		this->yyyy = yyyy;
	}
	int operator<(const Date& other)
	{
		return this->yyyy < other.yyyy;
	}
	int operator>(const Date& other)
	{
		return this->yyyy > other.yyyy;
	}
	int operator==(const Date& other)
	{
		return this->yyyy == other.yyyy && this->dd == other.dd && this->mm == other.mm;
	}
};

int main() {
	SetConsoleOutputCP(1251);

	Date date1(25, 11, 2024);
	Date date2(12, 5, 2023);
	Date date3(25, 11, 2024);

	const char* answers[] = { "ложь", "истина" };

	cout << answers[date1 < date2] << endl;
	cout << answers[date1 > date2] << endl;
	cout << answers[date1 == date2] << endl;
	cout << answers[date1 == date3] << endl;

	return 0;
}

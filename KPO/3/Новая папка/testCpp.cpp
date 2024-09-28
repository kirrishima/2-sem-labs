#include <iostream>
#include <sstream>
#include "functions.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Ru");
	char date[9]; // ДДММГГГГГ + символ завершения строки
	cin >> date;

	istringstream iss(date);

	char day_c[3], month_c[3], year_c[5];
	int day, month, year;

	iss.read(day_c, 2);
	day_c[2] = '\0';

	iss.read(month_c, 2);
	month_c[2] = '\0';

	iss.read(year_c, 4);
	year_c[4] = '\0';

	day = stoi(day_c);
	month = stoi(month_c);
	year = stoi(year_c);

	// Проверка корректности введенной даты
	if (month < 1 || month > 12 || day < 1 || day > daysInMonth[month] + (month == 2 && isLeapYear(year)))
	{
		cout << "Некорректная дата!" << endl;
		exit(EXIT_FAILURE);
	}

	// 1. Проверка на високосный год
	cout << "Год " << (isLeapYear(year) ? "високосный" : "не високосный") << endl;

	// 2. Вычисление порядкового номера дня в году
	cout << "Порядковый номер дня в году: " << dayOfYear(day, month, year) << endl;


	// 3. Вычисление дней до ближайшего дня рождения
	int birthdayDay = 26;
	int birthdayMonth = 4;
	int daysUntilBirthday = daysUntilNextBirthday(birthdayDay, birthdayMonth, day, month, year);

	cout << "Дней до ближайшего дня рождения: " << daysUntilBirthday << endl;
	getchar();
	getchar();
	return 0;
}

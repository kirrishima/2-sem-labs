#include "functions.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Ru");
	int day, month, year;
	inputDate(&day, &month, &year);
	bool isCurrentYearIsLeapYear = isLeapYear(year);
	int currentDayNumber = dayOfYear(day, month, year);
	// Проверка корректности введенной даты
	if (month < 1 || month > 12)
	{
		cout << "Некорректный месяц" << endl;
		exit(EXIT_FAILURE);
	}
	else if (day < 1 || day > daysInMonth[month - 1] + (month == 2 && isCurrentYearIsLeapYear))
	{
		cout << "Некорректное число дней в месяце" << endl;
		exit(EXIT_FAILURE);
	}
	else if (year < 0) {
		cout << "Некорректный год" << endl;
		exit(EXIT_FAILURE);
	}

	// 1. Проверка на високосный год
	cout << "Год " << (isCurrentYearIsLeapYear ? "високосный" : "не високосный") << endl;

	// 2. Вычисление порядкового номера дня в году
	cout << "Порядковый номер дня в году: " << currentDayNumber << endl;

	// 3. Вычисление дней до ближайшего дня рождения
	int birthdayDay;
	int birthdayMonth;
	inputDate(&birthdayDay, &birthdayMonth);
	if (month < 1 || month > 12)
	{
		cout << "Некорректный месяц" << endl;
		exit(EXIT_FAILURE);
	}
	else if (day < 1 || day > daysInMonth[month - 1] + (month == 2 && isCurrentYearIsLeapYear))
	{
		cout << "Некорректное число дней в месяце" << endl;
		exit(EXIT_FAILURE);
	}
	int daysUntilBirthday = daysUntilNextBirthday(birthdayDay, birthdayMonth, currentDayNumber, year, isCurrentYearIsLeapYear);

	cout << "Дней до ближайшего дня рождения: " << daysUntilBirthday << endl;
	getchar();
	getchar();
	return 0;
}

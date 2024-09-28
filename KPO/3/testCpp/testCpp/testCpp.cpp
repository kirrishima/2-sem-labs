#include "stdafx.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Ru");
	int day, month, year;
	inputDate(&day, &month, &year);
	bool isCurrentYearIsLeapYear = isLeapYear(year);
	int currentDayNumber = dayOfYear(day, month, year);

	if (!isValidDate(month, day, isCurrentYearIsLeapYear, &year))
	{
		std::cerr << "Неправильный формат даты, выход из программы. . .";
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

	if (!isValidDate(birthdayMonth, birthdayDay, isCurrentYearIsLeapYear))
	{
		std::cerr << "Неправильный формат даты, выход из программы. . .";
		exit(EXIT_FAILURE);
	}
	int daysUntilBirthday = daysUntilNextBirthday(birthdayDay, birthdayMonth, currentDayNumber, year, isCurrentYearIsLeapYear);
	cout << "Дней до ближайшего дня рождения: " << daysUntilBirthday << endl;
	cout << "\nВведите порядковый номер месяца в году: ";
	int monthNumber;
	cin >> monthNumber;
	cout << "Месяц с порядковым номером " << monthNumber << ": " << getMonthName(monthNumber) << endl;
	cout << "\nВведите порядковый номер дня день, в который произойдет событие: ";
	int dayOrder;
	cin >> dayOrder;
	calculateEventDate(dayOrder, year);
	return 0;
}

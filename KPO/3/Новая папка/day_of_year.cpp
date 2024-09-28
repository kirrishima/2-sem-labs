#include "functions.h"
// функция для вычисления порядкового номера дня в году
int dayOfYear(int day, int month, int year)
{


	int result = day;

	for (int i = 1; i < month; ++i)
	{
		result += daysInMonth[i];
	}

	if (month > 2 && isLeapYear(year))
	{
		result += 1; // Добавляем один день високосного года
	}

	return result;
}
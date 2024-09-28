#include "functions.h"
// Функция для вычисления дней до ближайшего дня рождения
int daysUntilNextBirthday(int birthdayDay, int birthdayMonth, int currentDayNumber, int currentYear, bool isCurrentLeap)
{
	int x = dayOfYear(birthdayDay, birthdayMonth, currentYear) - currentDayNumber;
	return (x < 0) ? 365 + isCurrentLeap + (((birthdayMonth > 2) || (birthdayMonth == 2 && birthdayDay == 29)) && isLeapYear(currentYear + 1)) + x : x;
}
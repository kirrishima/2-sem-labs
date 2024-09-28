#include "functions.h"
// Функция для вычисления дней до ближайшего дня рождения
int daysUntilNextBirthday(int birthdayDay, int birthdayMonth, int currentDay, int currentMonth, int currentYear)
{
	int x = dayOfYear(birthdayDay, birthdayMonth, currentYear) - dayOfYear(currentDay, currentMonth, currentYear);
	return (x < 0) ? 365 + isLeapYear(currentYear + 1) + (((birthdayMonth > 2) || (birthdayMonth == 2 && birthdayDay == 29)) && isLeapYear(currentYear + 1)) + x : x;
}
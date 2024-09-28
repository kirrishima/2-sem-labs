#include "stdafx.h"
// Функция для вычисления даты года для события с указанным порядковым номером
void calculateEventDate(int eventOrdinal, int year)
{
	int currentDay = 0;
	int currentMonth = 0;

	for (int i = 1; i <= 12; ++i)
	{
		int daysInCurrentMonth = daysInMonth[i];

		if (i == 2 && isLeapYear(year))
			daysInCurrentMonth++;

		if (eventOrdinal <= currentDay + daysInCurrentMonth)
		{
			currentMonth = i;
			break;
		}

		currentDay += daysInCurrentMonth;
	}

	int eventDay = eventOrdinal - currentDay;
	cout << "Событие с порядковым номером " << eventOrdinal << " в " << year << " году "
		<< " произойдет " << eventDay << " " << getMonthName(currentMonth) << "(a)" << endl;
}
#include "stdafx.h"
// ‘ункци€ дл€ вычислени€ даты года дл€ событи€ с указанным пор€дковым номером
void calculateEventDate(int eventOrdinal, int year)
{
	int currentDay = 0;
	int currentMonth = 0;

	for (int i = 1; i <= 12; ++i)
	{
		int daysInCurrentMonth = daysInMonth[i];

		if (i == 2 && isLeapYear(year))
			daysInCurrentMonth++; // ƒобавл€ем день в феврале дл€ високосного года

		if (eventOrdinal <= currentDay + daysInCurrentMonth)
		{
			currentMonth = i;
			break;
		}

		currentDay += daysInCurrentMonth;
	}

	int eventDay = eventOrdinal - currentDay;
	cout << "—обытие с пор€дковым номером " << eventOrdinal << " в " << year << " году "
		<< " произойдет " << eventDay << " " << getMonthName(currentMonth) << "(a)" << endl;
}
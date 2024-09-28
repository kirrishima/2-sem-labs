#include "stdafx.h"

const char* getMonthName(int month)
{
	const char* monthNames[] = { "Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь" };

	return monthNames[month - 1];
}
#include "functions.h"

// ������� ��� ���������� ����������� ������ ��� � ����
int dayOfYear(int day, int month, int year)
{


	int result = day;

	for (int i = 1; i < month; ++i)
	{
		result += daysInMonth[i-1];
	}

	if (month > 2 && isLeapYear(year))
	{
		result += 1; // ��������� ���� ���� ����������� ����
	}

	return result;
}
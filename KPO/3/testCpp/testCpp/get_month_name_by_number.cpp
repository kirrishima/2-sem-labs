#include "stdafx.h"

const char* getMonthName(int month)
{
	const char* monthNames[] = { "������", "�������", "����", "������", "���", "����", "����", "������", "��������", "�������", "������", "�������" };

	return monthNames[month - 1];
}
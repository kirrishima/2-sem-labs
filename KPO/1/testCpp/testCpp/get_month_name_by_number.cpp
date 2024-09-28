#include "stdafx.h"

const char* getMonthName(int month)
{
	const char* monthNames[] = { "������", "�������", "����", "������", "���", "����",
								 "����", "������", "��������", "�������", "������", "�������" };

	if (month >= 1 && month <= 12)
		return monthNames[month - 1];
	else
		return "������������ ����� ������";
}
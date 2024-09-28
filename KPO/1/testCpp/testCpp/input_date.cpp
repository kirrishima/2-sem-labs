#include "functions.h"

void inputDate(int* day, int* month, int* year) {
	if (day == nullptr || month == nullptr) {
		cerr << "�������� ������� ��������� ��� ��� ��� ������\n";
		exit(EXIT_FAILURE);
	}
	char date[9]; // ��������� + ������ ���������� ������
	if (year != nullptr) {
		cout << "������� ������� ���� � ������� ���������: "; cin >> date;
	}
	else {
		cout << "������� ���� � ����� �������� � ������� ����: "; cin >> date;
	}

	istringstream iss(date);

	char day_c[3], month_c[3], year_c[5];

	iss.read(day_c, 2);
	day_c[2] = '\0';

	iss.read(month_c, 2);
	month_c[2] = '\0';

	*day = stoi(day_c);
	*month = stoi(month_c);

	if (year != nullptr)
	{
		iss.read(year_c, 4);
		year_c[4] = '\0';
		*year = stoi(year_c);
	}
}
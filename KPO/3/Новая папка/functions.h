#ifndef FUNCTIONS_H
#define FUNCTIONS_H

const int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int daysUntilNextBirthday(int birthdayDay, int birthdayMonth, int currentDay, int currentMonth, int currentYear);
int dayOfYear(int day, int month, int year);
bool isLeapYear(int year);
#endif 
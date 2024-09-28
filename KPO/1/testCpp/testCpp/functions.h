#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <sstream>
using namespace std;

const int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int daysUntilNextBirthday(int birthdayDay, int birthdayMonth, int currentDay, int currentYear, bool isCurrentLeap);
int dayOfYear(int day, int month, int year);
bool isLeapYear(int year);
void inputDate(int* day, int* month, int* year = nullptr);
#endif 
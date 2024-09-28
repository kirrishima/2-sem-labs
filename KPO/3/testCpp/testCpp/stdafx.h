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
bool isValidDate(const int& month, const int& day, bool isYearIsLeap, const int* year = nullptr);
const char* getMonthName(int month);
void calculateEventDate(int eventOrdinal, int year);
#endif 
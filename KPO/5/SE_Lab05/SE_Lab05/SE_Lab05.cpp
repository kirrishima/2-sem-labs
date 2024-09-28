#include <Windows.h>
#include <iostream>
#include "Dictionary.h"
#include <cstring>
using namespace std;

int main() {
	SetConsoleOutputCP(1251);
	char a[20];
	strncpy_s(a, "Преподаватели", 14);
	Dictionary::Instance d1 = Dictionary::Create(a, 5); // создание с 
	Dictionary::Entry e1 = { 1, "Гладкий" }, e2 = { 2, "Веялкин" }, e3 = { 3, "Смелов" }, e4 = { 4, "Урбанович" }, e5 = { 5, "Пацей" };
	Dictionary::AddEntry(d1, e1);
	Dictionary::AddEntry(d1, e2);
	Dictionary::AddEntry(d1, e2);
	Dictionary::AddEntry(d1, e3);
	Dictionary::AddEntry(d1, e4);
	Dictionary::AddEntry(d1, e5);
	Dictionary::Print(d1);
	Dictionary::DelEntry(d1, 2);
	Dictionary::Print(d1);
	Dictionary::AddEntry(d1, e2);
	Dictionary::Print(d1);
	int aasa = 12;
	//добавление
	//добавление
	//добавление
	//добавление
	return 0;
}

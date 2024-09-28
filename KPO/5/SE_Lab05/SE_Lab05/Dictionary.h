#pragma once
#include <cstring>
#include <iostream>
#define DICTNAMEMAXSIZE 20
#define DICTMAXSIZE 100
#define ENTRYNAMEMAXSIZE 30

// маскисальный размер имени словаря // маскисальная емкость словаря
// маскисальная длина имени в словаре
#define THROW01 "Create: превышен размер имени словаря"
#define THROW02 "Create: превышен размер максимальной емкости словаря" 
#define THROW03 "AddEntry: переполнение словаря"
#define THROW04 "AddEntry: дублирование идентификатора"
#define THROWØ5 "GetEntry: не найден элемент"
#define THROW06 "DelEntry: не найден элемент" #define THROW07 "UpdEntry: не найден элемент" #define THROW08 "UpdEntry: дублирование идентификатора"
namespace Dictionary //
{
	struct Entry
		// элемент словаря
	{
		int id;
		// идентификатор (уникальный)
		char name[ENTRYNAMEMAXSIZE];
		// сивольная информация
	};
	struct Instance
	{
		// экземпляр словаря
		char name[DICTNAMEMAXSIZE];
		int maxsize;
		// наименование словаря
		int size = 0;
		Entry* dictionaгу;
		// максимальная емкость словаря
		// текущий размер словаря << DICTNAMEMAXSIZE // массив элементов словаря
		// создать словарь
	};
	Instance Create(
		char name[DICTNAMEMAXSIZE], int size
	);
	void AddEntry(
		// имя словаря
		// емкость словаря << DICTNAMEMAXSIZE
		// добавить элемент словаря
		Instance& inst, Entry ed
		// экземпляр словаря
		// элемент словаря
		// экземпляр словаря
	);
	void DelEntry(Instance& inst,
		// удалить элемент словаря Instances inst,
		int id);
	// идентификатор удаляемого элемента (уникальный)
	void UpdEntry( // изменить элемент словаря
		Instance& inst,
		int id,
		Entry new_ed
		// экземпляр словаря
		// идентификатор заменяемого элемента
		// новыый элемент словаря
		// экземпляр словаря
	);
	Entry* GetEntry(
		// получить элемент словаря 
		Instance inst,
		int id
	);
	void Print(const Instance& d); void Delete(Instance& d);
	// идентификатор получаемого элемента
	// печать словаря
	// удалить словарь
}
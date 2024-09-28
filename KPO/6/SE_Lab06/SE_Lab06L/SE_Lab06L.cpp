
#include "pch.h"
#include "framework.h"

#include "Dictionary.h"

namespace Dictionary {

	Instance Create(const char* name, int size)
	{
		Instance dictObj;

		if (strlen(name) > DICTNAMEMAXSIZE) {
			throw THROW01;
		}
		if (size > DICTMAXSIZE || size <= 0) {
			throw THROW02;
		}

		strncpy_s(dictObj.name, name, DICTNAMEMAXSIZE);
		dictObj.maxsize = size;
		dictObj.dictionaгу = new Entry[size];
		return dictObj;
	}

	void AddEntry(Instance& inst, Entry ed)
	{
		if (inst.size == inst.maxsize)
		{
			throw THROW03;
		}
		for (size_t i = 0; i < inst.size; i++)
		{
			if (inst.dictionaгу[i].id == ed.id) {
				throw THROW04;
			}
		}
		inst.dictionaгу[inst.size++] = ed;
	}

	void DelEntry(Instance& inst, int id)
	{
		for (size_t i = 0; i < inst.size; i++)
		{
			if (inst.dictionaгу[i].id == id) {
				for (size_t j = i; j < inst.size - 1; j++)
				{
					inst.dictionaгу[j] = inst.dictionaгу[j + 1];
				}
				inst.size--;
				return;
			}
		}
		throw THROW06;
	}

	void UpdEntry(Instance& inst, int id, Entry new_ed)
	{
		for (size_t i = 0; i < inst.size; i++)
		{
			if (inst.dictionaгу[i].id == new_ed.id)
			{
				throw THROW08;
			}
		}
		for (size_t i = 0; i < inst.size; i++)
		{
			if (inst.dictionaгу[i].id == id)
			{
				inst.dictionaгу[i] = new_ed;
				return;
			}
		}
		throw THROW07;
	}

	Entry* GetEntry(Instance inst, int id)
	{
		for (size_t i = 0; i < inst.size; i++)
		{
			if (inst.dictionaгу[i].id == id)
			{
				return &inst.dictionaгу[i];
			}
		}
		throw THROW05;
		return nullptr;
	}

	void Print(const Instance& d)
	{
		for (size_t i = 0; i < d.size; i++)
		{
			std::cout << "Id: " << d.dictionaгу[i].id << ", Name: " << d.dictionaгу[i].name << " \n";
		}
		std::cout << '\n';
	}

	void Delete(Instance& d)
	{
		delete[] d.dictionaгу;
	}
}

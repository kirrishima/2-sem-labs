#include "Dictionary.h"
#include <stdexcept>
namespace Dictionary {
#define STR(x) #x
	Instance Create(char name[DICTNAMEMAXSIZE], int size)
	{
		Instance dictObj;

		if (size <= 0) {
			throw std::invalid_argument("Размер коллекции должен быть положительным числом");
		}
		if (size > DICTMAXSIZE) {
			throw std::invalid_argument("Указанный размер превышает максимально допустимый("  STR(DICTMAXSIZE)  ")");
		}


		strncpy_s(dictObj.name, name, DICTNAMEMAXSIZE);
		dictObj.maxsize = size;
		//dictObj.size = 0;
		dictObj.dictionaгу = new Entry[size];
		return dictObj;
	}
	void AddEntry(Instance& inst, Entry ed)
	{
		if (inst.size == inst.maxsize)
		{
			std::cerr << "Словарь полн\n";
			return;
		}
		for (size_t i = 0; i < inst.size; i++)
		{
			if (inst.dictionaгу[i].id == ed.id) {
				std::cerr << "Индификартор для вхождения уже присутствует в словаре. " << ed.id << ": " << ed.name << "\n";
				return;
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
	}
	void UpdEntry(Instance& inst, int id, Entry new_ed)
	{
		for (size_t i = 0; i < inst.size; i++)
		{
			if (inst.dictionaгу[i].id == id)
			{
				inst.dictionaгу[i] = new_ed;
				return;
			}
		}
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
		return nullptr;
	}
	void Print(const Instance& d)
	{
		for (size_t i = 0; i < d.size; i++)
		{
			std::cout << d.dictionaгу[i].name << " ";
		}
		std::cout << '\n';
	}
	void Delete(Instance& d)
	{
		delete[] d.dictionaгу;
	}
}
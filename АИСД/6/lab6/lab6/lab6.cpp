#include <Windows.h>
#include <iostream>
#include <list>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

template <typename T>
class HashTable
{
private:

	struct Node
	{
		int key;
		T value;
		Node(int key, T value)
		{
			this->key = key;
			this->value = value;
		}
	};

	int size;
	std::vector<std::list<Node>> Data;

	int HashFunction(int key) {
		return key % size;
	}
public:
	HashTable(int size) : size(size), Data(size) {}

	void add(int key, T value) {
		Data[HashFunction(key)].push_back(Node(key, value));
	}
	bool pop(int key) {
		for (auto it = Data[HashFunction(key)].begin(); it != Data[HashFunction(key)].end(); it++) {
			if (it->key == key) {
				Data[HashFunction(key)].erase(it);
				return true;
			}
		}
		return false;
	}
	bool search(int key, T& result) {
		bool flag = false;
		auto start = std::chrono::high_resolution_clock::now();
		for (auto it = Data[HashFunction(key)].begin(); it != Data[HashFunction(key)].end(); it++) {
			if (it->key == key) {
				result = it->value;
				flag = true;
				break;
			}
		}
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
		std::cout << "Затрачено времени на поиск: " << duration.count() << " наносекунд" << std::endl;
		return flag;
	}

	void print() const {
		int count = 0;
		for (auto& list : Data)
		{
			std::cout << "Цепочка " << count++;
			if (list.empty()) {
				std::cout << " пуста";
			}
			for (auto& element : list)
			{
				std::cout << " | " << "key = " << element.key << ", value = " << element.value;
			}
			std::cout << '\n';
		}
	}
};


int main() {
	SetConsoleOutputCP(1251);

	//for (size_t i = 32; i < 129; i *= 2)
	//{
	//	HashTable<std::string> hashTable(i);
	//	int j = 0;
	//	for (; j != i * log2(i) * 5; j += i)
	//	{
	//		hashTable.add(j, "Михась Броука");
	//	}
	//	std::string res;
	//	hashTable.search(j - i, res);
	//}
	HashTable<std::string> hashTable(20);
	hashTable.add(12, "ao");
	hashTable.add(13, "ao");
	hashTable.add(14, "ao");
	hashTable.add(15, "ao");
	hashTable.add(16, "ao");
	hashTable.print();
	hashTable.pop(15);	hashTable.print();
	return 0;
}

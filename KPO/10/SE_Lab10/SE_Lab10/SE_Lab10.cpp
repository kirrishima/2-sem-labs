#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	std::vector<int> v{ 1,2,3,4,5,6,7,8,9,10 };
	int target1 = 3;

	int num_items1 = std::count(v.begin(), v.end(), target1);
	cout << "число: " << target1 << " количество: " << num_items1 << '\n';

	int num_items3 = std::count_if(v.begin(), v.end(), [](int i) {return i % 3 == 0; });
	cout << "количество элементов кратных 3: " << num_items3 << '\n';

	cout << endl << "Лямбда, захват переменных" << endl;
	for (auto i : v) [i]() {if (i % 3 == 0) cout << i << ' '; }();

	cout << endl << "Лямбда с параметрами" << endl;
	for (auto i : v) [](auto i) {if (i % 3 == 0) cout << i << ' '; }(i);

	cout << endl << "Лямбда без параметров" << endl;
	for (auto i : v) [i] {if (i % 3 == 0) cout << i << ' '; }();

	//int x = 12;
	//cout << endl << x << endl;
	//[&]()  {x = 1232; }();
	//cout << x << endl;
	//Разработать шаблонную лямбда - функцию для типов char, int, float для
	//	задачи 1. Для типа char вернуть true, если код символа в диапазоне от 1 до
	//	127 и false в противном случае
	auto func = [](auto value) {
		if (std::is_same_v<decltype(value), char>) {
			return 1 <= value && value <= 127;
		}
		else if (std::is_same_v<decltype(value), int>) {
			return value > 0;
		}
		else if (std::is_same_v<decltype(value), float >) {
			return value > 0;
		}
		throw"Неправильный тип";
		};
	cout << '\n';
	cout << func(12) << endl;
	cout << func(float(1.2)) << endl;
	cout << func('Я') << endl;
}
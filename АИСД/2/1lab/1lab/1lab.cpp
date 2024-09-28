//#include <iostream>
//#include <vector>
//#include <Windows.h>
//unsigned long long binarySearch(unsigned long long N) {
//	unsigned long long low = 1;
//	unsigned long long high = N;
//	int steps = 0;
//
//	while (low <= high) {
//		unsigned long long mid = low + (high - low) / 2;
//		std::cout << mid << std::endl;
//		steps++;
//		int maxSteps = 0;
//		std::string response;
//		std::cout << "Введите ответ ('мало', 'много', 'угадал'): ";
//		std::cin >> response;
//
//		if (response == "угадал") {
//			unsigned long long tmp = N;
//			while (tmp != 1) {
//				std::cout << tmp<<'\n';
//				tmp = 1 + (tmp - 1) / 2;
//				maxSteps++;
//			}
//			std::cout << "1\n";
//			std::cout << "Угадано за " << steps << " шагов" << std::endl;
//			std::cout << "Максимальное число шагов: " << maxSteps;
//			return mid;
//		}
//		else if (response == "мало") {
//			low = mid + 1;
//		}
//		else if (response == "много") {
//			high = mid - 1;
//		}
//		else {
//			std::cout << "Неверный ответ. Пожалуйста, введите 'мало', 'много' или 'угадал'" << std::endl;
//		}
//	}
//
//	return -1;  // В случае ошибки
//}
//
//int main() {
//	SetConsoleOutputCP(1251);
//	SetConsoleCP(1251);
//	unsigned long long N;
//	std::cout << "Введите число N: ";
//	std::cin >> N;
//
//	int guessedNumber = binarySearch(N);
//
//
//	return 0;
//}

#include <Windows.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int getCommon(vector<int>& nums1, vector<int>& nums2) {
		for (int i = 0; i < nums1.size(); i++) {
			int j;
			if (nums2.size() == 0)   return -1;
			for (j = 0; j < nums2.size() && nums2[j] <= nums1[i]; j++) {
				if (nums1[i] == nums2[j]) {
					return nums1[i];
				}

			}
			nums2.erase(nums2.begin(), nums2.begin() + j);

		}
		return -1;
	}
};

int main() {
	SetConsoleOutputCP(1251);

	Solution s;
	vector<int> a(3, 5);
	vector<int> b(2);
	cout << s.getCommon(a, b);

	return 0;
}

#include <Windows.h>
#include <stack>
#include <iostream>
using namespace std;

bool isValid(const std::string str)
{
	stack<char> stack;
	for (const char c : str)
	{
		if (c != '(' && c != '{' && c != '[' && c != ')' && c != '}' && c != ']')
		{
			continue;
		}
		if (c == '(' || c == '{' || c == '[')
		{
			stack.push(c);
		}
		else
		{
			if (stack.empty()
				|| stack.top() != '(' && c == ')'
				|| stack.top() != '{' && c == '}'
				|| stack.top() != '[' && c == ']')
			{
				return false;
			}
			stack.pop();
		}
	}
	return stack.empty();
}
int main() {
	SetConsoleOutputCP(1251);

	std::string str = "[1+ 12{fds - + 432}([])2]";
	std::string str1 = "([)]";

	const char* answers[] = { "скобки расставлены не верно", "скобки расставлены верно" };

	cout << answers[isValid(str)] << endl;
	cout << answers[isValid(str1)] << endl;

	return 0;
}

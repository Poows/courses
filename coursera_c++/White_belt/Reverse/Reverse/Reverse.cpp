// Reverse.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> Reverse(const vector<int>& v)
{
	vector<int> numbers;
	for (int i = v.size(); i > 0; i--)
	{
		numbers.push_back(v[i-1]);
	}
	for (auto w : numbers)
	{
		cout << w << " ";
	}
	return numbers;
}

int main()
{
	vector<int> numbers = { 1, 5, 3, 4, 2 };
	Reverse(numbers);
}


// NumberInDouble.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
#include <vector>

int main()
{
	vector<int> a;
	int number = 0;
	int flag = 0;
	cin >> number;

	while (number != 0)
	{
		a.push_back(number % 2);
		/*
		if (number % 2 != 0 || flag == 1) {
			a.push_back(number % 2);
			flag = 1;
		}
		*/
		number = number / 2;
	}
	for (int i = a.size(); i > 0; i--)
		cout << a[i - 1];
	return 0;
}



// StringCoursera.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;
int main()
{
	string my_string = "";

	cin >> my_string;

	int i = 0;
	int count = 0;
	int count_for_f = -1;
	int number = 0;

	for (auto i : my_string)
	{
		count_for_f++;
		if (i == 'f')
		{
			count++;
		}
		if (count == 2)
		{
			number = count_for_f;
			count++;
		}

	}
	if (count == 1) cout << -1;
	else if (count == 0) cout << -2;
	else cout << number;
	return 0;
}


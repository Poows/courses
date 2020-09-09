// palindrom.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int IsPalindrom(string x)
{
	string test;
	if (x == "") return true;
	for (int i = x.length(); i > 0; i--)
	{
		//cout << x[i - 1];
		test += x[i - 1];
	}
	if (test == x) return true;
	return false;
}

/*int main()
{
	string x;
	cin >> x;
	cout << IsPalindrom(x);
	return 0;
}*/





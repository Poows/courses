// Swap.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

void UpdateIfGreater(int first, int& second)
{
	int tmp = first;
	first = second;
	second = tmp;
	cout << second;
}

/*int main()
{
	int a = 4;
	int b = 2;
	UpdateIfGreater(a, b);
	cout << b;
}*/



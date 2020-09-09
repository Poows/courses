// ChetNumbers.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main()
{
	int A, B = 0;
	cin >> A >> B;
	for (int i = 0; i < B; i++)
	{
		if (A <= B)
		{
			if (A % 2 == 0)
			{
				cout << A << " ";
			}
			A++;
		}
	}
	return 0;
}



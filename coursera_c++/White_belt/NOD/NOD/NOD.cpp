// NOD.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;


int main()
{
	int A, B = 0;
	cin >> A >> B;
	while (A != 0 && B != 0)
	{
		if (A > B)
			A = A % B;
		else
			B = B % A;
	}
	cout << A + B;
	return 0;
}


// DelCoursera.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main()
{
	float N, A, B, X, Y;
	cin >> N >> A >> B >> X >> Y;
	X = (100 - X) / 100;
	Y = (100 - Y) / 100;
	if (N > B)
	{
		cout << N * Y;
	}
	else if (N > A)
	{
		cout << N * X;
	}
	else
	{
		cout << N;
	}
}


#include <iostream>
using namespace std;

int Factorial(int x)
{
	if (x < 0) return 1;
	if (x == 0) return 1;
	else return (x * Factorial(x - 1));
}
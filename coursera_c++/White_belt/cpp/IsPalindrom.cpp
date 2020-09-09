#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool IsPalindrom(string x)
{
	string test;
	if (x == "") return true;
	for (int i = x.length(); i > 0; i--)
	{
		test += x[i - 1];
	}
	if (test == x) return true;
	return false;
}
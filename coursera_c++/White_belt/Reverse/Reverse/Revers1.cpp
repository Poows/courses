#include <iostream>
#include <vector>
using namespace std;

void Reverse(vector<int>& v)
{
	vector<int> numbers = v;
	v.clear();
	for (int i = numbers.size(); i > 0; i--)
	{
		v.push_back(numbers[i - 1]);
	}
}
#include <iostream>
#include <vector>
using namespace std;

vector<int> Reversed(const vector<int>& v)
{
	vector<int> numbers;
	for (int i = v.size(); i > 0; i--)
	{
		numbers.push_back(v[i-1]);
	}
	return numbers;
}
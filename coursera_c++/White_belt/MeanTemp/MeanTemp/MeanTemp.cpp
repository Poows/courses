// MeanTemp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
using namespace std;

void PrintVector(const vector<int>& v)
{
	cout << v.size() << endl;
	for (auto s : v)
		cout << s << " ";
}

vector<int> NewVector(vector<int>& v, int& N)
{
	for (int i = 0; i < N; i++)
	{
		int w;
		cin >> w;
		v.push_back(w);
	}
	return v;
}

vector<int> MeanTemp(vector<int>& x)
{
	vector<int> count;
	int sum = 0;
	int mean = 0;
	for (int i = 0; i < x.size(); i++)
	{
		sum = sum + x[i];
	}
	mean = sum / x.size();

	for (int i = 0; i < x.size(); i++)
	{
		if (x[i] > mean)
		{
			count.push_back(i);
		}
	}
	x.clear();
	for (auto w : count)
	{
		x.push_back(w);
	}
	return x;
}

int main()
{
	int N = 0;
	cin >> N;
	vector<int> v;

	NewVector(v, N);
	MeanTemp(v);
	PrintVector(v);

	return 0;
}



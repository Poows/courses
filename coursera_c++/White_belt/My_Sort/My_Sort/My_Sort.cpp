// My_Sort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//bool my_fun(int i , int j)
//{
//	if (abs(i) < abs(j) & j < 0) return true;
//	return (abs(i) < abs(j);
//}

int main()
{
	setlocale(LC_ALL, "rus");
	/*vector<int> my_sort;
	int Q = 0;
	int num = 0;

	cin >> Q;

	for (int i = 0; i < Q; i++)
	{
		cin >> num;
		my_sort.push_back(num);
	}

	sort(my_sort.begin(), my_sort.end(), [](int i, int j) {return (abs(i) < abs(j)); });

	for (const auto& item : my_sort)
	{
		cout << item << " ";
	}*/
	int stop = 0;
	int input = 0;
	while (stop == 0)
	{
		cin >> input;
		switch (input) {
		case 1:
			cout << "1" << endl;
			break;
		case 2:
			cout << "2" << endl;
			break;
		case 3:
			cout << "3" << endl;
			break;
		case 4:
			stop = 1;
			break;
		default:
			break;
		}
	}
}



// Register.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool my_fnc(string i, string j)
{
	string str = "";

	char i_2 = '\0';
	string str_2 = "";

	if (i.length() < j.length()) return true;
	else if (i.length() == j.length())
	{
		if (i.length() && j.length() == 1)
		{
			if (tolower(i[0]) < tolower(j[0])) return true;
			else
			{
				return false;
			}
		}

		int flag = 0;
		for (int cnt = 0; cnt < i.size(); cnt++)
		{
			str += tolower(i[cnt]);
		}
		flag = 0;
		for (int cnt_2 = 0; cnt_2 < j.size(); cnt_2++)
		{
			str_2 += tolower(j[cnt_2]);
		}
		if (str < str_2) return true;
		//if (i <= j) return true;
		else return false;
	}
	else if (i.length() > j.length()) return false;
}

int main()
{
	int Q = 0;
	vector<string> my_str;
	string str;
	string second_str = "";
    
	cin >> Q;

	for (int i = 0; i < Q; i++)
	{
		cin >> str;
		my_str.push_back(str);
	}
	sort(my_str.begin(), my_str.end(), my_fnc);

	for (const auto& item : my_str)
	{
		cout << item << " ";
	}
}


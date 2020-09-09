// Turn.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

/*WORRY i : пометить i - го человека с начала очереди(в нумерации с 0) как беспокоящегося;
QUIET i : пометить i - го человека как успокоившегося;
COME k : добавить k спокойных человек в конец очереди;
COME - k: убрать k человек из конца очереди;
WORRY_COUNT: узнать количество беспокоящихся людей в очереди.*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> CheckCom(string& com, int& id, int& come, vector<int>& worry, vector<int>& quiet, vector<int>& worry_count)
{
	int schet = 0;
	if (com == "COME" && id > 0)
	{
		come += id;
	}
	if (com == "COME" && id < 0)
	{
		for (int i = 0; i < worry.size(); i++)
		{
			if (worry[i] >= (come + id) && worry[i] <= come)
			{
				worry[i] = -1;
			}
		}
		come = come + id;
	}
	if (com == "WORRY")
	{
		worry.push_back(id);
	}
	if (com == "QUIET")
	{
		for (int i = 0; i < worry.size(); i++)
		{
			if (worry[i] == id)
			{
				worry[i] = -1;
			}
		}
	}
	if (com == "WORRY_COUNT")
	{
		for (auto w : worry) {
			if (w == -1)	schet++;
		}
		worry_count.push_back(worry.size() - schet);
	}
	return worry_count;
}

int main()
{
	int come = 0;
	vector<int> worry;
	vector<int> worry_count;
	vector<int> quiet;
	vector<int> exodus;

	int Q = 0;
	vector<string> comands;

	cin >> Q;

	for (int i = 0; i < Q; i++)
	{
		string com;
		int id;
		cin >> com;
		if (com == "WORRY_COUNT") {
			CheckCom(com, id, come, worry, quiet, worry_count);
		}
		else
		{ 
			cin >> id;
			CheckCom(com, id, come, worry, quiet, worry_count);
		}
		com = "";
	}

	for (auto w : worry_count)
		cout << w << endl;

	return 0;
}



// Sinonim.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main()
{
	int Q = 0;
	int cnt = 0;
	string command, word, word_1, word_2;
	map<string, set<string>> sinonim;
	vector<string> print;
	string my_string = "";
	set<string> my_set;

	cin >> Q;


	for (int i = 0; i < Q; i++)
	{
		cin >> command;

		if (command == "ADD")
		{
			cin >> word_1 >> word_2;
			{
				auto it = sinonim.find(word_1);
				if (it == sinonim.end())
				{
					set<string> ss;
					ss.insert(word_2);
					sinonim.insert(pair<string, set<string>>(word_1, ss));
				}
				else
				{
					(it->second).insert(word_2);
				}
			}
			{
				auto it = sinonim.find(word_2);
				if (it == sinonim.end())
				{
					set<string> ss;
					ss.insert(word_1);
					sinonim.insert(pair<string, set<string>>(word_2, ss));
				}
				else
				{
					(it->second).insert(word_1);
				}
			}
		}
		else if (command == "COUNT")
		{
			cin >> word;

			//set<string> word_sin;

			int count = 0;
			auto it = sinonim.find(word);
			if (it != sinonim.end())
			{
				//word_sin.insert((it->second).begin(), (it->second).end());
				my_string += to_string(it->second.size()) + "\n";
			}
			else my_string += "0\n";

			//print.push_back(to_string(word_sin.size()));
		}
		else if (command == "CHECK")
		{
			cin >> word_1 >> word_2;

			int count = 0;
			auto it = sinonim.find(word_1);
			if (it != sinonim.end()) count = (it->second).count(word_2);
			if (count > 0) my_string += "YES\n";//print.push_back("YES");
			else
			{
				it = sinonim.find(word_2);
				if (it != sinonim.end()) count = (it->second).count(word_1);
				if (count > 0) my_string += "YES\n";//print.push_back("YES");
				else           my_string += "NO\n";//print.push_back("NO");
			}
		}
	}
	cout << my_string;
}
// Country.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<string> Change_capital(string& country, string& new_copital, map<string, string>& country_name, vector<string>& dump)
{
	int flag = 0;

	if (!country_name.empty())
	{
		for (auto& i : country_name)
		{
			if (i.first == country)
			{
				if (i.second == new_copital)
				{
					dump.push_back("Country " + country + " hasn't changed its capital");
					flag = 1;
				}
				else
				{
					dump.push_back("Country " + country + " has changed its capital from " + i.second + " to " + new_copital);
					i.second = new_copital;
					flag = 1;
				}
			}
		}
		if (flag == 0)
		{
			country_name[country] = new_copital;
			dump.push_back("Introduce new country " + country + " with capital " + new_copital);
		}
		flag = 0;
	}

	if (country_name.empty())
	{
		country_name[country] = new_copital;
		dump.push_back("Introduce new country " + country + " with capital " + new_copital);
	}

	return dump;
}

void Rename(string& old_country_name, string& new_name_country, map<string, string>& country_name, vector<string>& dump)
{
	int flag = 0;

	if (old_country_name == new_name_country) {
		dump.push_back("Incorrect rename, skip");
		return;
	}

	for (auto& i : country_name)
	{
		if (i.first == new_name_country) {
			dump.push_back("Incorrect rename, skip");
			return;
		}
	}

	if (!country_name.empty())
	{
		for (auto& i : country_name)
		{
			if (i.first == new_name_country) dump.push_back("Incorrect rename, skip");
			if (i.first == old_country_name)
			{
				if (!i.second.empty())
				{
					dump.push_back("Country " + old_country_name + " with capital " + i.second + " has been renamed to " + new_name_country);
					country_name[new_name_country] = i.second;
					i.second = "";
					country_name.erase(i.first);
					flag = 1;
					return;
				}
			}
		}
		if (flag == 0) dump.push_back("Incorrect rename, skip");
	}
	else dump.push_back("Incorrect rename, skip");
}

void About(string& country, map<string, string>& country_name, vector<string>& dump)
{
	int flag = 0;

	for (auto& i : country_name)
	{
		if (i.first == country)
		{
			dump.push_back("Country " + i.first + " has capital " + i.second);
			flag = 1;
		}
	}

	if (flag == 0) dump.push_back("Country " + country + " doesn't exist");

	flag = 0;
}

void Dump(map<string, string>& country_name, vector<string>& dump, int& flag)
{
	string cnt_string = "";
	if (country_name.empty()) dump.push_back("There are no countries in the world");
	else
	{
		for (auto& i : country_name)
		{
			if (flag == 0) {
				cnt_string += i.first + "/" + i.second;
				flag = 1;
			}
			else
			{
				cnt_string += " " + i.first + "/" + i.second;
			}
		}
		dump.push_back(cnt_string);
	}
	cnt_string = "";
	flag = 0;
}

int main()
{
	int flag = 0;
	vector<string> dump;
	map<string, string> country_name;
	string command, country, new_copital;
	string old_country_name, new_country_name;
	string about_country;
	int Q = 0;

	cin >> Q;

	for (int i = 0; i < Q; i++)
	{
		cin >> command;

		if (command == "CHANGE_CAPITAL")
		{
			cin >> country >> new_copital;
			Change_capital(country, new_copital, country_name, dump);
		}

		if (command == "RENAME")
		{
			cin >> old_country_name >> new_country_name;
			Rename(old_country_name, new_country_name, country_name, dump);
		}

		if (command == "ABOUT")
		{
			cin >> about_country;
			About(about_country, country_name, dump);
		}

		if (command == "DUMP")
		{
			Dump(country_name, dump, flag);
		}

	}

	for (auto& i : dump)
	{
		cout << i << endl;
	}
}



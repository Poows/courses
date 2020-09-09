// Names.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Person
{
public:
	void ChangeFirstName(int year, const string& first_name) {
		auto it = getLastAccount(year, first_n);
		if (it != first_n.end() && it->second == first_name) return;
		it = getNextAccount(year, first_n);
		if (it != first_n.end() && it->second == first_name)
		{
			//first_n.erase(it->first);
			return;
		}

		first_n[year] = first_name;
		count_names[first_name]++;
		// добавить факт изменения имени на first_name в год year
	}
	void ChangeLastName(int year, const string& last_name) {
		//auto it = getLastAccount(year, last_n);
		//if (it != last_n.end() && it->second == last_name) return;
		//it = getNextAccount(year, last_n);
		//if (it != last_n.end() && it->second == last_name) 
		//{
		//	//last_n.erase(it->first);
		//	return;
		//}

		last_n[year] = last_name;
		count_names[last_name]++;
		// добавить факт изменения фамилии на last_name в год year
	}
	string GetFullName(int year) {
		if (!(first_n.empty() && last_n.empty()))
		{
			if (GetName(year, first_n) == "Incognito") {
				if (GetName(year, last_n) == "Incognito") {
					return "Incognito";
				}					
				else {
					return GetName(year, last_n) + " with unknown first name";
				}
			}
			else if (GetName(year, last_n) == "Incognito") {	
				return GetName(year, first_n) + " with unknown last name";
			}
			else {

				return GetName(year, first_n) + " " + GetName(year, last_n);
			}
		}
		else
		{
			return "Incognito";
		}
		// получить имя и фамилию по состоянию на конец года year
	}
	string GetFullNameWithHistory(int year) {
		if (!(first_n.empty() && last_n.empty()))
		{
			if (GetName(year, first_n) == "Incognito") {
				if (GetName(year, last_n) == "Incognito") {
					return "Incognito";
				}
				else {
					return  GetFullName(year, last_n) + " with unknown first name";
				}
			}
			else if (GetName(year, last_n) == "Incognito") {
				return GetFullName(year, first_n) + " with unknown last name";
			}
			else {
				return GetFullName(year, first_n) + " " + GetFullName(year, last_n);
			}
		}
		else
		{
			return "Incognito";
		}
		// получить все имена и фамилии по состоянию на конец года year
	}

private:
	string GetName(int year, map<int, string>& name)
	{
		int flag = 0;
		int save_flag = 0;
		string check_name = "";
		string save_name = "";
		for (auto& i : name)
		{
			if (i.first <= year) {
				check_name = i.second;
				flag = 1;
			}
		}
		if (flag == 0) {
			return "Incognito";
		}
		else {
			return check_name;
		}
	}

	map<int, string>::iterator getLastAccount(int year, map<int, string>& name)
	{
		auto it = name.find(year);
		if (it != name.end()) return it;

		auto res_it = name.end();
		for (it = name.begin(); it != name.end(); it++)
		{
			if (it->first > year) break;
			res_it = it;
		}

		return res_it;
	}

	map<int, string>::iterator getNextAccount(int year, map<int, string>& name)
	{
		auto res_it = name.end();
		for (auto it = name.begin(); it != name.end(); it++)
		{
			if (it->first > year)
			{
				res_it = it;
				break;
			}
		}

		return res_it;
	}

	string GetFullName(int year, map<int, string>& name) {

		int flag = 0;
		int save_flag = 0;
		string check_name = "";
		string save_name = "";
		auto it_check = name.end();


		auto it = getLastAccount(year, name);
		if (it == name.end())
		{
			return check_name;
		}
		else
		{
			while (true)
			{
				if (flag == 2)
				{
					check_name += ", " + it->second;
				}
				if (flag == 1)
				{
					if (it_check->second != it->second)
					{
						check_name += " (" + it->second;
						flag = 2;
					}
				}
				if (flag == 0)
				{
					check_name += it->second;
					flag = 1;
				}
				if (it != name.begin()) {
					it_check = it;
					it--;
				}
				else
				{
					if (flag > 1) check_name += ")";
					break;
				}
			}
		}

		return check_name;
	}

	map<int, string> first_n;
	map<int, string> last_n;
	map<string, int> count_names;
	vector<string> new_names;
};

//int main() {
//	Person person;
//
//	person.ChangeFirstName(1965, "Polina");
//	person.ChangeFirstName(1965, "Appolinaria");
//
//	person.ChangeLastName(1965, "Sergeeva");
//	person.ChangeLastName(1965, "Volkova");
//	person.ChangeLastName(1965, "Volkova-Sergeeva");
//
//	for (int year : {1964, 1965, 1966}) {
//		cout << person.GetFullNameWithHistory(year) << endl;
//	}
//
//	return 0;
//}


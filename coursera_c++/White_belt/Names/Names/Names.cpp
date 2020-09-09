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

	Person(string first_name, string last_name, int year){
		auto it = getLastAccount(year, first_n);
		if (it != first_n.end() && it->second == first_name) return;
		it = getNextAccount(year, first_n);
		if (it != first_n.end() && it->second == first_name)
		{
			//first_n.erase(it->first);
			return;
		}

		first_n[year] = first_name;
		last_n[year] = last_name;
	}


	void ChangeFirstName(const int year, const string& first_name) {
		auto it_ch = first_n.begin();
		if (year < it_ch->first) return;
		auto it = getLastAccount(year, first_n);
		if (it != first_n.end() && it->second == first_name) return;
		it = getNextAccount(year, first_n);
		if (it != first_n.end() && it->second == first_name)
		{
			//first_n.erase(it->first);
			return;
		}

		first_n[year] = first_name;
		// добавить факт изменения имени на first_name в год year
	}
	void ChangeLastName(const int year, const string& last_name) {
		//auto it = getLastAccount(year, last_n);
		//if (it != last_n.end() && it->second == last_name) return;
		//it = getNextAccount(year, last_n);
		//if (it != last_n.end() && it->second == last_name) 
		//{
		//	//last_n.erase(it->first);
		//	return;
		//}
		auto it_ch = last_n.begin();
		if (year < it_ch->first) return;
		last_n[year] = last_name;
		// добавить факт изменения фамилии на last_name в год year
	}
	string GetFullName(const int year) const {
		if (!(first_n.empty() && last_n.empty()))
		{
			if (GetName(year, first_n) == "No person") {
				if (GetName(year, last_n) == "No person") {
					return "No person";
				}					
				else {
					return GetName(year, last_n) + " with unknown first name";
				}
			}
			else if (GetName(year, last_n) == "No person") {	
				return GetName(year, first_n) + " with unknown last name";
			}
			else {

				return GetName(year, first_n) + " " + GetName(year, last_n);
			}
		}
		else
		{
			return "No person";
		}
		// получить имя и фамилию по состоянию на конец года year
	}
	string GetFullNameWithHistory(const int year) const {
		//min(begin(first_n), end(first_n));
		if (!(first_n.empty() && last_n.empty()))
		{
			if (GetName(year, first_n) == "No person") {
				if (GetName(year, last_n) == "No person") {
					return "No person";
				}
				else {
					return GetFullName(year, last_n) + " with unknown first name";
				}
			}
			else if (GetName(year, last_n) == "No person") {
				return GetFullName(year, first_n) + " with unknown last name";
			}
			else {
				return GetFullName(year, first_n) + " " + GetFullName(year, last_n);
			}
		}
		else
		{
			return "No person";
		}
		// получить все имена и фамилии по состоянию на конец года year
	}

private:
	string GetName(int year, const map<int, string>& name) const
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
			return "No person";
		}
		else {
			return check_name;
		}
	}

	map<int, string>::const_iterator getLastAccount(int year, const map<int, string>& name) const
	{
		auto it = name.find(year);
		if (it != name.cend()) return it;

		auto res_it = name.end();
		for (auto it = name.begin(); it != name.end(); it++)
		{
			if (it->first > year) break;
			res_it = it;
		}
		auto const r_it = res_it;
		return r_it;
	}

	map<int, string>::iterator getNextAccount(int year, map<int, string>& name) const
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

	string GetFullName(const int year, const map<int, string>& name) const {

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

int main() {
	Person person("Polina", "Sergeeva", 1960 );

	for (int year : {1959, 1960}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeFirstName(1965, "Appolinaria");
	person.ChangeLastName(1967, "Ivanova");
	for (int year : {1965, 1967}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	return 0;
}


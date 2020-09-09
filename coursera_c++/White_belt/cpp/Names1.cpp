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
		first_n[year] = first_name;
		// добавить факт изменения имени на first_name в год year
	}
	void ChangeLastName(int year, const string& last_name) {
		last_n[year] = last_name;
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

private:

	string GetName(int year, map<int, string>& name)
	{
		int flag = 0;
		string check_name = "";
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

	map<int, string> first_n;
	map<int, string> last_n;
};

//int main()
//{
//	Person person;
//
//	person.ChangeFirstName(1965, "Polina");
//	person.ChangeLastName(1967, "Sergeeva");
//	for (int year : {1900, 1965, 1990}) {
//		cout << person.GetFullName(year) << endl;
//	}
//
//	person.ChangeFirstName(1970, "Appolinaria");
//	for (int year : {1969, 1970}) {
//		cout << person.GetFullName(year) << endl;
//	}
//
//	person.ChangeLastName(1968, "Volkova");
//	for (int year : {1969, 1970}) {
//		cout << person.GetFullName(year) << endl;
//	}
//
//	return 0;
//}


#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <stdlib.h>
using namespace std;

class Date {
public:
	Date() {
		day = 0;
		month = 0;
		year = 0;
	};
	int init(int day, int month, int year);

	int GetYear() const
	{
		return year;
	}
	int GetMonth() const
	{
		return month;
	}
	int GetDay() const
	{
		return day;
	}
	string GetString() const {
		int flag = 0;
		int l_year = year;
		if (year < 0) {
			flag = 1;
			l_year = -year;
		}
		string str_year = to_string(l_year);
		string str_month = to_string(month);
		string str_day = to_string(day);
		int year_ln = str_year.length();
		int month_ln = str_month.length();
		int day_ln = str_day.length();
		for (int i = 0; i < 4 - year_ln; i++) {
			str_year = '0' + str_year;
		}
		if (flag == 1) str_year = '-' + str_year;
		for (int i = 0; i < 2 - month_ln; i++) {
			str_month = '0' + str_month;
		}
		for (int i = 0; i < 2 - day_ln; i++) {
			str_day = '0' + str_day;
		}
		return str_year + "-" + str_month + "-" + str_day;
	}

private:
	int year;
	int month;
	int day;
};

int Date::init(int day, int month, int year) {
	if (month > 12 || month < 1) return -1;
	if (day > 31 || day < 1) return -2;
	this->day = day;
	this->month = month;
	this->year = year;
	return 0;
}

bool operator<(const Date& lhs, const Date& rhs) {
	if (lhs.GetYear() < rhs.GetYear()) return true;
	if (lhs.GetYear() > rhs.GetYear()) return false;
	if (lhs.GetMonth() < rhs.GetMonth()) return true;
	if (lhs.GetMonth() > rhs.GetMonth()) return false;
	if (lhs.GetDay() < rhs.GetDay()) return true;
	return false;
}

struct cmpDate {
	bool operator()(const Date& a, const Date& b) const {
		return a < b;
	}
};

class Database {
public:
	void AddEvent(const Date& date, const string& event);
	bool DeleteEvent(const Date& date, const string& event);
	int  DeleteDate(const Date& date);
	int GetDataEvents(Date& date);

	void Find(const Date& date) const;

	void Print() const;

	vector<string> _print;
private:
	map<Date, set<string>, cmpDate> db;
};

int Database::GetDataEvents(Date& date) {
	try {
		int N = 0;

		auto it = db.find(date);

		if (it == db.end()) return 0;

		N = it->second.size();

		return N;
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
		return 0;
	}
}

void Database::Find(const Date& date) const
{
	try {
		auto it = db.find(date);
		if (it == db.end()) {
			return;
		}

		for (auto it_ss = (it->second).cbegin(); it_ss != (it->second).cend(); it_ss++)
		{
			string ev = *it_ss;
			cout << ev << endl;
		}
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
	}
}

void Database::Print() const 
{
	try {
		for (auto it = db.cbegin(); it != db.cend(); it++) {
			string s = it->first.GetString();
			for (auto it_s = it->second.cbegin(); it_s != it->second.cend(); it_s++) {
				string w = *it_s;
				cout << s + " " + w << endl;
			}
		}
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
	}
}

void Database::AddEvent(const Date& date, const string& event) {
	try {
		auto it = db.find(date);
		if (it != db.end()) {
			it->second.insert(event);
		}
		else {
			set<string> ss;
			ss.insert(event);
			db[date] = ss;
		}
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
	}
}

bool Database::DeleteEvent(const Date& date, const string& event) {
	try {
		auto it = db.find(date);
		if (it == db.end()) {
			return false;
		}

		set<string>& ss = it->second;
		auto it_ss = ss.find(event);
		if (it_ss == ss.end()) return false;
		ss.erase(it_ss);

		return true;
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
		return false;
	}
}

int  Database::DeleteDate(const Date& date) {
	try {
		auto it = db.find(date);
		if (it == db.end()) {
			return 0;
		}

		db.erase(it->first);
		return 1;
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
		return 0;
	}
}

bool GetDateFromStr(string str_data, int& year, int& month, int& day) 
{
	bool form_ok = true;
	bool month_ok = true;
	bool day_ok = true;

	string str_year = "";
	string str_month = "";
	string str_day = "";
	string str_month_year = "";

	int pos_month;
	int count = 0;
	int i_start;

	int pos = str_data.find_last_of("-");
	if (pos == -1) {
		form_ok = false;
		goto FINISH;
	}

	str_day = str_data.substr(pos + 1);
	str_month_year = str_data.substr(0, pos);
	

	while (true)
	{
		if (str_month_year[str_month_year.length() - 1] == '-') {
			str_day = "-" + str_day;
			str_month_year = str_month_year.substr(0, str_month_year.length() - 1);
			count++;
		}
		else {
			break;
		}
	}
	if (count > 1)
	{
		cout << "Wrong date format: " + str_data << endl;
		return false;
	}

	pos_month = str_month_year.find_last_of("-");

	if (pos_month == -1) {
		form_ok = false;
		goto FINISH;
	}

	str_month = str_month_year.substr(pos_month + 1);
	str_year = str_month_year.substr(0, pos_month);

	count = 0;
	while (true)
	{
		if (str_year[str_year.length() - 1] == '-') {
			str_month = "-" + str_month;
			str_year = str_year.substr(0, str_year.length() - 1);
			count++;
		}
		else {
			break;
		}
	}
	if (count > 1)
	{
		cout << "Wrong date format: " + str_data << endl;
		return false;
	}

	// -1-+11-+15

	if (str_month[0] == '+') {
		str_month = str_month.substr(1);
		if (str_month[0] == '+') {
			form_ok = false;
			goto FINISH;
		}
	}

	i_start = 0;
	if (str_month[0] == '-')
	{
		month_ok = false;
		i_start = 1;
	}
	if (str_month.length() == 0)
	{
		form_ok = false;
		goto FINISH;
	}
	for (int i = i_start; i < str_month.length(); i++)
	{
		if (!('0' <= str_month[i] && str_month[i] <= '9'))
		{
			form_ok = false;
			goto FINISH;
		}
	}

	i_start = 0;
	if (str_day[0] == '+') {
		str_day = str_day.substr(1);
		if (str_day[0] == '+') {
			form_ok = false;
			goto FINISH;
		}
	}
	if (str_day[0] == '-')
	{
		day_ok = false;
		i_start = 1;
	}
	if (str_day.length() == 0)
	{
		form_ok = false;
		goto FINISH;
	}
	for (int i = i_start; i < str_day.length(); i++)
	{
		if (!('0' <= str_day[i] && str_day[i] <= '9'))
		{
			form_ok = false;
			goto FINISH;
		}
	}

	month = atoi(str_month.c_str());
	day = atoi(str_day.c_str());
	year = atoi(str_year.c_str());

	if (month < 1 || month > 12) {
		month_ok = false;
		goto FINISH;
	}
	if (day < 1 || day > 31) {
		day_ok = false;
		goto FINISH;
	}

FINISH:
	if (!form_ok)
	{
		cout << "Wrong date format: " + str_data << endl;
		return false;
	}
	if (!month_ok)
	{
		cout << "Month value is invalid: " + to_string(month) << endl;
		return false;
	}
	if (!day_ok)
	{
		cout << "Day value is invalid: " + to_string(day) << endl;
		return false;
	}

	return true;
}



int main() {
	Database db;

	string command;
	while (getline(cin, command)) {
		if (command == "") continue;
		int pos = command.find(" ");
		if (pos == -1) {
			if (command == "Print") {
				db.Print();
				continue;
			}
			else {
				cout << "Unknown command: " + command << endl;
				continue;
			}
		}
		string str_com = command.substr(0, pos);
		if (str_com == "Add") {
			string str_arg = command.substr(pos + 1);
			int pos_arg = str_arg.find(" ");
			if (pos_arg == -1) {
				cout << "Wrong date format:  " << endl;
				continue;
			}
			string str_data = str_arg.substr(0, pos_arg);
			string str_event = str_arg.substr(pos_arg + 1);
			int year = 0;
			int month = 0;
			int day = 0;

			if (!GetDateFromStr(str_data, year, month, day)) continue;

			Date date;

			date.init(day, month, year);

			db.AddEvent(date, str_event);

			continue;
		} 
		if (str_com == "Del") {

			int year = 0;
			int month = 0;
			int day = 0;

			string str_arg = command.substr(pos + 1);
			int pos_arg = str_arg.find(" ");
			if (pos_arg == -1) {

				if (!GetDateFromStr(str_arg, year, month, day)) continue;

				Date date;

				date.init(day, month, year);

				int N = db.GetDataEvents(date);

				db.DeleteDate(date);

				cout << "Deleted " + to_string(N) + " events" << endl;
				continue;
			}
			else {
				int pos_arg = str_arg.find(" ");

				string str_arg = command.substr(pos + 1);
				string str_data = str_arg.substr(0, pos_arg);
				string str_event = str_arg.substr(pos_arg + 1);

				if (!GetDateFromStr(str_data, year, month, day)) continue;

				Date date;

				date.init(day, month, year);

				if (db.DeleteEvent(date, str_event)) cout << "Deleted successfully" << endl;
				else cout << "Event not found" << endl;
				continue;
			}
		}
		if (str_com == "Find") {
			string str_data = command.substr(pos + 1);

			int year = 0;
			int month = 0;
			int day = 0;

			if (!GetDateFromStr(str_data, year, month, day)) continue;

			Date date;

			date.init(day, month, year);

			db.Find(date);

			continue;
		}
		cout << "Unknown command: " + command << endl;
		continue;
	}

	return 0;
}

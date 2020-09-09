// DaysAndMonth.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main()
{
	int count = 0;
	int count_mouth = 0;
	string locale_name;
	int Q = 0;
	vector<int> month = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	vector<int> my_data;
	vector<int> month_case_list_cnt(31);
	vector<string> print_event;

	vector<vector<int>> test(12);

	vector<int>    month_case_cnt(31, 0); // количество дел на дни месяца
	vector<string> month_case_list(31, ""); // список дел на дни месяца


	cin >> Q;

	for (auto i : month_case_list_cnt)
	{
		i = 0;
	}

	bool ADD_DONE = false;
	for (int i = 0; i < Q; i++)
	{
		string comand;
		int index;
		string name;
		int prev_count = 0;

		cin >> comand;
		if (comand == "NEXT")
		{
			count++;

			if (ADD_DONE)
			{
				prev_count = count - 1;
				if (count == 12)
				{
					count = 0;
					prev_count = 11;
				}

				for(int day = month[count]; day < month[prev_count]; day++)
				{
					int month_last_day = month[count] - 1;
					month_case_cnt[month_last_day] += month_case_cnt[day];
					month_case_cnt[day] = 0;
					
					if (month_case_list[day] != "")
					{
						if (month_case_list[month_last_day] != "") month_case_list[month_last_day] += " ";
						month_case_list[month_last_day] += month_case_list[day];

						month_case_list[day] = "";
					}
				} 
			}
		}
		else if (comand == "DUMP")
		{
			cin >> index;
			
			string out_event = "";
			if (month_case_cnt[index - 1] > 0)
			{
				out_event = std::to_string(month_case_cnt[index - 1]) + " " + month_case_list[index - 1];
			}
			else out_event = "0";

			print_event.push_back(out_event);
		}
		else if (comand == "ADD")
		{
			ADD_DONE = true;

			cin >> index >> name;

			month_case_cnt[index - 1] += 1;
			if (month_case_list[index - 1] != "") month_case_list[index - 1] += " ";
			month_case_list[index - 1] += name;
		}
	}

	for (int i = 0; i < print_event.size(); i++)
	{
		cout << print_event[i] << endl;
	}

	return 0;
}



//int main()
//{
//	int count = 0;
//	int count_mouth = 0;
//	string locale_name;
//	int Q = 0;
//	vector<int> month = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//
//	vector<int> my_data;
//	vector<int> month_case_list_cnt(31);
//	vector<string> print_event;
//
//	vector<vector<int>> test(12);
//
//	vector<int>    month_case_cnt(31, 0); // количество дел на дни месяца
//	vector<string> month_case_list(31, ""); // список дел на дни месяца
//
//
//	cin >> Q;
//
//	for (auto i : month_case_list_cnt)
//	{
//		i = 0;
//	}
//
//	bool ADD_DONE = false;
//	for (int i = 0; i < Q; i++)
//	{
//		string comand;
//		int index;
//		string name;
//		int prev_count = 0;
//
//		cin >> comand;
//		if (comand == "NEXT")
//		{
//			count++;
//
//			if (ADD_DONE)
//			{
//				prev_count = count - 1;
//				if (count == 12)
//				{
//					count = 0;
//					prev_count = 11;
//				}
//
//				test[count].insert(end(test[count]), begin(test[prev_count]), end(test[prev_count]));
//				test[prev_count].clear();
//
//				if (month[count] < month[prev_count])
//				{
//					int flag = 0;
//					for (int i = 0; i < test[count].size(); i++)
//					{
//						if (test[count][i] > month[count])
//						{
//							if (flag == 0)
//							{
//								locale_name += month_case_list[i];
//								flag++;
//							}
//							else
//							{
//								locale_name = locale_name + " " + month_case_list[i];
//							}
//						}
//					}
//
//					flag = 0;
//					for (int i = 0; i < test[count].size(); i++)
//					{
//						if (test[count][i] > month[count])
//						{
//							month_case_list[i] = "";
//						}
//						if (test[count][i] == month[count])
//						{
//							flag = 1;
//							month_case_list[i] += " " + locale_name;
//						}
//					}
//					if (flag == 0)
//					{
//						test[count].push_back(month[count]);
//						for (int i = 0; i < test[count].size(); i++)
//						{
//							if (test[count][i] == month[count])
//							{
//								month_case_list.push_back(locale_name);
//							}
//						}
//					}
//					locale_name = "";
//				}
//			}
//		}
//		else if (comand == "DUMP")
//		{
//			cin >> index;
//			for (int i = 0; i < test[count].size(); i++)
//			{
//				if (test[count][i] == index)
//				{
//					print_event.push_back(month_case_list[i]);
//				}
//			}
//		}
//		else if (comand == "ADD")
//		{
//			ADD_DONE = true;
//			string add_string;
//			int flag_1 = 0;
//			cin >> index >> name;
//
//			for (int i = 0; i < test[count].size(); i++)
//			{
//				if (index == test[count][i])
//				{
//					if (month_case_list[i] == "")
//					{
//						add_string = add_string + name;
//						flag_1 = 1;
//						month_case_list[i] += add_string;
//					}
//					else
//					{
//						add_string = add_string + " " + name;
//						flag_1 = 1;
//						month_case_list[i] += add_string;
//					}
//				}
//			}
//
//			if (flag_1 == 0)
//			{
//				test[count].push_back(index);
//				month_case_list.push_back(name);
//			}
//			flag_1 = 0;
//		}
//	}
//
//	int flag_2 = 0;
//	int count_2 = 0;
//	for (int i = 0; i < print_event.size(); i++)
//	{
//		for (int j = 0; print_event[i][j] != '\0'; j++)
//		{
//			if (print_event[i][j] != ' ' && flag_2 == 0) {
//				count_2 += 1;
//				flag_2 = 1;
//			}
//			else
//				if (print_event[i][j] == ' ') flag_2 = 0;
//		}
//		month_case_list_cnt[i] = count_2;
//		count_2 = 0;
//		flag_2 = 0;
//	}
//
//	for (int i = 0; i < print_event.size(); i++)
//	{
//		cout << month_case_list_cnt[i] << " " << print_event[i] << endl;
//	}
//
//	return 0;
//}



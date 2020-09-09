
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main()
{
	int Q = 0;

	int number = 0;
	int check = 0;
	string command = "";
	map<int, vector<string>> bus_and_stop;
	map<int, set<string>> bus_and_stop_2;
	set<string> local_bus;
	vector<string> bus_print;

	cin >> Q;

	for (int i = 0; i < Q; i++)
	{
		if (bus_and_stop_2.empty())
		{
			cin >> number;
			for (int j = 0; j < number; j++)
			{
				cin >> command;
				bus_and_stop_2[1].insert(command);
			}
			bus_print.push_back("New bus 1");
		}
		else
		{
			int flag = 0;
			int count = 0;
			int local_size = 0;
			int local_size_first = 0;
			int local_size_second = 0;
			cin >> number;

			for (int g = 0; g < number; g++)
			{
				cin >> command;
				local_bus.insert(command);
			}

			for (auto& item : bus_and_stop_2)
			{
				if (item.second == local_bus)
				{
					bus_print.push_back("Already exists for " + to_string(item.first));
					flag = 1;
				}
			}

			if (flag == 0)
			{
				for (auto& m : bus_and_stop_2)
				{
					check = m.first;
				}
				check += 1;

				bus_and_stop_2[check].insert(begin(local_bus), end(local_bus));
				string loc_str = "";
				loc_str = "New bus " + to_string(check);
				bus_print.push_back(loc_str);
				loc_str = "";
			}
			flag = 0;
		}
		local_bus.clear();
	}

	int i = 0;

	for (auto& i : bus_print)
	{
		cout << i << endl;
	}
}

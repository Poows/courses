// bus_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int Q = 0;

	int number = 0;
	int check = 0;
	string command = "";
	map<int, vector<string>> bus_and_stop;
	vector<string> local_bus;
	vector<string> bus_print;

	cin >> Q;

	for (int i = 0; i < Q; i++)
	{
		if (bus_and_stop.empty())
		{
			cin >> number;
			for (int j = 0; j < number; j++)
			{
				cin >> command;
				bus_and_stop[1].push_back(command);
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
				local_bus.push_back(command);
			}

			for (auto& item : bus_and_stop)
			{
				/*local_size_first = local_bus.size();
				local_size_second = item.second.size();
				if (local_size_first == local_size_second)
				{
					for (int cnt = 0; cnt < local_bus.size(); cnt++)
					{
						if (item.second[cnt] == local_bus[cnt])
						{
							count++;
						}
					}
				}
				local_size = item.second.size();
				if (count == local_size)
				{
					bus_print.push_back("Already exists for " + to_string(item.first));
					flag = 1;
				}*/

				if (item.second == local_bus)
				{
					bus_print.push_back("Already exists for " + to_string(item.first));
					flag = 1;
				}
			}

			if (flag == 0)
			{
				for (auto& m : bus_and_stop)
				{
					check = m.first;
				}
				check += 1;
				for (int m = 0; m < local_bus.size(); m++)
				{
					bus_and_stop[check].push_back(local_bus[m]);
				}
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



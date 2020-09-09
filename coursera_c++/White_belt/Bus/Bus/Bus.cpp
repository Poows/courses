
#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main()
{
	int Q = 0;
	int stop_count;
	map<string, vector<string>> bus;
	map<string, vector<string>> second_bus;
	map<string, vector<string>> third_bus;
	string command, name_bus, stop_n;

	vector<string> bus_print;
	vector<string> bus_print_2;

	cin >> Q;

	for (int i = 0; i < Q; i++)
	{
		cin >> command;

		int flag = 0;
		int flag_1 = 0;
		string bus_stop_name = "";

		if (command == "NEW_BUS")
		{
			cin >> name_bus >> stop_count;

			int check_2 = 0;

			for (int j = 0; j < stop_count; j++)
			{
				cin >> stop_n;
				if (bus.empty())
				{
					bus[stop_n].push_back(name_bus);
					second_bus[name_bus].push_back(stop_n);
				}
				else
				{
					for (auto& m : bus)
					{
						if (m.first == stop_n)
						{
							for (int v = 0; v < m.second.size(); v++)
							{
								if (m.second[v] == name_bus)
								{
									check_2 = 1;
								}
							}
							if (check_2 == 0)
							{
								m.second.push_back(name_bus);
								flag = 1;
							}
						}
						check_2 = 0;
					}
					if (flag == 0)
					{
						bus[stop_n].push_back(name_bus);
						flag = 0;
					}

					for (auto& g : second_bus)
					{
						if (g.first == name_bus)
						{
							g.second.push_back(stop_n);
							flag_1 = 1;
						}
					}
					if (flag_1 == 0)
					{
						second_bus[name_bus].push_back(stop_n);
						flag_1 = 0;
					}
				}
				flag = 0;
				flag_1 = 0;
			}
		}
		else if (command == "BUSES_FOR_STOP")
		{
			cin >> stop_n;

			string rtp = "";

			flag = 0;
			int flag_g = 0;

			for (const auto& u : bus)
			{
				if (u.first == stop_n)
				{
					for (int r = 0; r < u.second.size(); r++)
					{
						if (flag_g == 0)
						{
							rtp += u.second[r];
							flag_g = 1;
						}
						else
						{
							rtp += " " + u.second[r];
						}
					}
					bus_print.push_back(rtp);
					flag_g = 0;
					flag = 1;
				}
			}
			if (flag == 0)
			{
				bus_print.push_back("No stop");
			}
		}
		else if (command == "STOPS_FOR_BUS")
		{
			cin >> name_bus;

			int check = 0;

			for (auto& yy : second_bus)
			{
				if (yy.first == name_bus) check = 1;
			}
			int flag_for_name_bus = 0;

			if (check == 1)
			{
				for (const auto& my_bus : bus)
				{
					for (int x = 0; x < my_bus.second.size(); x++)
					{
						if (my_bus.second[x] == name_bus)
						{
							if (my_bus.second.size() == 1)
							{
								third_bus[my_bus.first].push_back("no interchange");
							}
							else
							{
								for (int y = 0; y < my_bus.second.size(); y++)
								{
									if (my_bus.second[y] != name_bus)
									{
										third_bus[my_bus.first].push_back(my_bus.second[y]);
									}
								}
							}
						}
					}
				}

				string rtp = "";
				for (auto& t : second_bus)
				{
					if (t.first == name_bus)
					{
						for (int tf = 0; tf < t.second.size(); tf++)
						{
							for (auto& gf : third_bus)
							{
								if (gf.first == t.second[tf])
								{
									rtp += "Stop " + gf.first + ":";
									for (int ff = 0; ff < gf.second.size(); ff++)
									{
										rtp += " " + gf.second[ff];
									}
								}
							}
							bus_print.push_back(rtp);
							rtp = "";
						}
					}
				}
			}
			else
			{
				bus_print.push_back("No bus");
			}
			third_bus.clear();
		}
		else if (command == "ALL_BUSES")
		{
			string rtp = "";
			if (second_bus.empty())
			{
				bus_print.push_back("No buses");
			}
			else
			{
				for (auto& rr : second_bus)
				{
					rtp += "Bus " + rr.first + ":";
					for (int q = 0; q < rr.second.size(); q++)
					{
						rtp += " " + rr.second[q];
					}
					bus_print.push_back(rtp);
					rtp = "";
				}
			}
		}
	}

	for (auto& item : bus_print)
	{
		cout << item << endl;
	}

}


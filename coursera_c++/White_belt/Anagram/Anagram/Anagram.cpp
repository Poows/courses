// Anagram.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

//vector<string> BuildCharCounters(vector<string>& w_1, vector<string>& w_2)
//{
//	
//}

int main()
{
	int Q = 0;
	char t;
	int count = 0;
	int flag = 0;
	vector<string> w_1;
	vector<string> w_2;
	vector<string> output;
	string first_word;
	string second_word;
	map<char, int> m_1;
	map<char, int> m_2;

	cin >> Q;

	for (int i = 0; i < Q; i++)
	{
		cin >> first_word >> second_word;
		w_1.push_back(first_word);
		w_2.push_back(second_word);
	}

	for (int i = 0; i < w_1.size(); i++)
	{
		for (int j = 0; j < w_1[i].size(); j++)
		{
			t = w_1[i][j];
			for (auto h : m_1)
			{
				if (h.first == t)
				{
					m_1[t] += 1;
					flag = 1;
				}
			}
			if (flag == 0)
			{
				m_1[t] = 1;
			}
			flag = 0;
		}

		for (int j = 0; j < w_2[i].size(); j++)
		{
			t = w_2[i][j];
			for (auto h : m_2)
			{
				if (h.first == t)
				{
					m_2[t] += 1;
					flag = 1;
				}
			}
			if (flag == 0)
			{
				m_2[t] = 1;
			}
			flag = 0;
		}
		if (m_1 == m_2) output.push_back("YES");
		else output.push_back("NO");
		m_1.clear();
		m_2.clear();
		count = 0;
	}

	for (const auto& i : output)
	{
		cout << i << endl;
	}
}


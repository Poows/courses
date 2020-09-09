// Table.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <stdlib.h>
#include <sstream>

using namespace std;

vector<string> my_split(string& my_string) {
	vector<string> words;
	string dgts = "0123456789";

	string word = "";
	for (int i = 0; i < my_string.length(); i++) 
	{
		char c = my_string[i];
		if (c == ',')
		{
			words.push_back(word);
			word = "";
			continue;
		}
		if (dgts.find(c) < 0) continue;
		word += c;
	}
	words.push_back(word);
	return words;
}

int main()
{
	ifstream input("input.txt");
	int flag = 0;
	string line = "";


	while (getline(input, line)) {
		if (flag > 0) {
			vector<string> row;
			row = my_split(line);
			for (int i = 0; i < row.size(); i++)
			{
				//cout << setw(11 - row[i].length());
				//cout << row[i];
				//if (i < row.size() - 1) cout << " ";

				cout << setw(10) << row[i];
				string w = (i < row.size() - 1) ? " " : "";
				cout << w;
			}
			cout << endl;
		}
		flag = 1;
	}
	return 0;
}

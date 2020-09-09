// WorkFile2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	ifstream input("input.txt");
	string line = "";
	ofstream output("output.txt");

	while (getline(input, line))
	{
		output << line << endl;
		cout << line << endl;
	}

	ifstream input2("output.txt");

	//while (getline(input2, line))
	//{
	//	cout << line << endl;
	//}
	return 0;
}


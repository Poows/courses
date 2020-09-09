// PalindromFilter.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
using namespace std;

vector<string> PalindromFilter(vector<string> words, int minLength)
{
	string text;
	string test;
	vector<string> my_vector;
	for (int i = 0; i < words.size(); i++)
	{
		text = words[i];
		for (int j = text.length(); j > 0; j--)
		{
			test += text[j - 1];
		}
		if (text == test && test.length() >= minLength) my_vector.push_back(text);
		test = "";
	}
	return my_vector;
}

int main()
{
	vector<string> x = { "abacaba", "aba" };
	vector<string> y = PalindromFilter(x, 2);
	for (int i = 0; i < y.size(); i++)
		cout << y[i] << ", ";
	return 0;
}



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
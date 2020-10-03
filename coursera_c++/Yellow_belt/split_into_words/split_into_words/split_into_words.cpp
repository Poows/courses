// split_into_words.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<string> SplitIntoWords(const string& s) {
	vector<string> res;
	string word = "";

	for (auto it = s.begin(); it != s.end(); it++) {

		if (*it != ' ') {
			word += *it;
		}
		else {
			res.push_back(word);
			word = "";
		}
	}

	res.push_back(word);

	return res;
}

int main()
{
	string s = "C Cpp Java Python";

	vector<string> words = SplitIntoWords(s);
	cout << words.size() << " ";
	for (auto it = begin(words); it != end(words); ++it) {
		if (it != begin(words)) {
			cout << "/";
		}
		cout << *it;
	}
	cout << endl;

	return 0;
}


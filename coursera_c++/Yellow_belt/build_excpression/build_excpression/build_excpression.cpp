// build_excpression.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

int main()
{
	string res;
	string x;
	size_t N;
	cin >> x;
	cin >> N;

	res = x;

	getline(cin, x);

	if (N == 0) {
		cout << x;
	}
	else {
		res = "(" + res + ")";

		for (size_t i = 0; i < N; i++) {
			getline(cin, x);
			res = res + " " + x;
			if (i != (N - 1)) {
				res = "(" + res + ")";
			}
			else {

			}
		}
	}
	cout << res << endl;
}


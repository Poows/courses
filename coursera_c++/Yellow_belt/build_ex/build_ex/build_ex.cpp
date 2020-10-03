
#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

int main()
{
	deque<string> deq;
	string res;
	string x = "";
	size_t N;
	cin >> x;
	cin >> N;
	char prev = ' ';

	res = x;

	getline(cin, x);

	if (N == 0) {
		cout << res << endl;
	}
	else {
		deq.push_back(res);

		for (size_t i = 0; i < N; i++) {
			getline(cin, x);

			if (x[0] == '*' || x[0] == '/') {
				if (prev == '+' || prev == '-') {
					deq.push_front("(");
					deq.push_back(")");
				}
			}

			deq.push_back(" " + x);
			prev = x[0];
		}
	}
	
	for (auto& i : deq) {
		cout << i;
	}
}
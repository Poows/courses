// print_permutatuions.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <sstream>
#include <math.h>

using namespace std;

template<class T>
ostream& operator << (ostream& os, vector<T>& v) {
	for (const auto& i : v) {
		os << i << " ";
	}
	return os;
}

int fact(int n) {

	return (n == 0) || (n == 1) ? 1 : n * fact(n - 1);
}

int main()
{
	int N = 0;

	cin >> N;

	vector<int> v;
	for (int i = 1; i <= N; i++) {
		v.push_back(i);
	}

	N = fact(N);

	for (int i = 0; i < N; i++) {
		prev_permutation(begin(v), end(v));
		cout << v << endl;
	}
}



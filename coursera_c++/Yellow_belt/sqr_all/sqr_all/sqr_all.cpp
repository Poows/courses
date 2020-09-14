// sqr_all.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <map>
#include <vector>
#include <utility>

using namespace std;

template<class T> T Sqr(T x);
template<class T> vector<T> operator * (const vector<T>& v1, const vector<T>& v2);
template<class rhs, class lhs> pair<rhs, lhs> operator * (const pair<rhs, lhs>& p1, const pair<rhs, lhs>& p2);
template<class key, class value> map<key, value> operator * (const map<key, value>& m1, const map<key, value>& m2);

template<class T>
T Sqr(T x)
{
	return x * x;
}

template<class T>
vector<T> operator * (const vector<T>& v1, const vector<T>& v2) {

	vector<T> nv;

	for (size_t i = 0; i < v1.size(); i++) {
		nv.push_back(v1[i] * v1[i]);
	}

	return nv;
}

template<class rhs, class lhs>
pair<rhs, lhs> operator * (const pair<rhs, lhs>& p1, const pair<rhs, lhs>& p2) {
	pair<rhs, lhs> np = pair<rhs, lhs>(p1.first * p1.first, p1.second * p1.second);

	return np;
}

template<class key, class value>
map<key, value> operator * (const map<key, value>& m1, const map<key, value>& m2) {

	map<key, value> nm;

	for (auto& i : m1) {
		nm.insert(pair<key, value>(i.first, i.second * i.second));
	}

	return nm;
}

int main()
{
	vector<int> v = { 1, 2, 3 };

	cout << "vector:";

	for (const auto& x : Sqr(v)) {
		cout << ' ' << x;
	}
	cout << endl;

	map<int, pair<int, int>> map_of_pairs = {
	  {4, {2, 2}},
	  {7, {4, 3}}
	};

	cout << "map of pairs:" << endl;

	for (const auto& x : Sqr(map_of_pairs)) {
		cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
	}
}



// find_starts_with_char.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <limits>
#include <math.h>
#include <algorithm>

using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
	RandomIt range_begin, RandomIt range_end,
	const string& prefix);

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, const string& prefix) {

	pair<RandomIt, RandomIt> prefix_range;
	
	if (prefix == "") {
		return { range_begin, range_begin };
	}

	if (range_begin == range_end) {
		return { range_begin, range_end };
	}

	auto check_in = lower_bound(range_begin, range_end, prefix);
	auto n = check_in;

	if (check_in == range_end) {
		return { check_in, check_in };
	}

	string p = "";
	for (size_t i = 0; i < prefix.length(); i++) {
		p += (*n)[i];
	}

	if (p != prefix) {
		return {check_in, check_in};
	}

	prefix_range.first = check_in;

	auto it = next(prefix_range.first);

	string pp = p;
	
	pp[prefix.length() - 1]++;

	//for (auto iter = it; iter != range_end; iter++) {
	//	for (size_t i = 0; i < prefix.length(); i++) {
	//		p += (*iter)[i];
	//	}
	//	if (p != prefix) {
	//		prefix_range.second = iter;
	//	}
	//	p = "";
	//}

	auto it_l = lower_bound(it, range_end, pp);

	if (it_l == range_end) {
		prefix_range.second = it_l;
	}
	else {
		prefix_range.second = it_l;
	}

	return prefix_range;
}

int main() {
	const vector<string> sorted_strings = { "moscow", "motovilikha", "murmansk" };

	const auto mo_result =
		FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
	for (auto it = mo_result.first; it != mo_result.second; ++it) {
		cout << *it << " ";
	}
	cout << endl;

	const auto mt_result =
		FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
	cout << (mt_result.first - begin(sorted_strings)) << " " <<
		(mt_result.second - begin(sorted_strings)) << endl;

	const auto na_result =
		FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
	cout << (na_result.first - begin(sorted_strings)) << " " <<
		(na_result.second - begin(sorted_strings)) << endl;

	return 0;
}

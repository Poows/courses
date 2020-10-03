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
	char prefix);

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, char prefix) {

	pair<RandomIt, RandomIt> prefix_range;

	if (range_begin == range_end) {
		return { range_begin, range_end };
	}

	string p;
	p.push_back(prefix);

	auto check_in = lower_bound(range_begin, range_end, p);

	if (check_in == range_end) {
		return { check_in, check_in };
	}

	if ((*check_in)[prefix.size()] != prefix) {
		return { check_in, check_in };
	}

	prefix_range.first = check_in;

	++p[0];

	auto it = next(prefix_range.first);
	auto it_l = lower_bound(it, range_end, p);

	if (it_l == range_end) {
		prefix_range.second = it_l;
	}
	else {
		prefix_range.second = it_l;
	}

	return prefix_range;
}

int main() {
	const vector<string> sorted_strings = { "moscow", "murmansk", "vologda" };

	const auto m_result =
		FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
	for (auto it = m_result.first; it != m_result.second; ++it) {
		cout << *it << " ";
	}
	cout << endl;

	const auto p_result =
		FindStartsWith(begin(sorted_strings), end(sorted_strings), 'p');
	cout << (p_result.first - begin(sorted_strings)) << " " <<
		(p_result.second - begin(sorted_strings)) << endl;

	const auto z_result =
		FindStartsWith(begin(sorted_strings), end(sorted_strings), 'z');
	cout << (z_result.first - begin(sorted_strings)) << " " <<
		(z_result.second - begin(sorted_strings)) << endl;

	return 0;
}

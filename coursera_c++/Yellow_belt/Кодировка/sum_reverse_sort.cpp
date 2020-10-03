#include <iostream>
#include "sum_reverse_sort.h"
#include <sstream>
#include <exception>
#include <string>
#include <map>
#include <set>
#include <limits>
#include <algorithm>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
	os << "{";
	bool first = true;
	for (const auto& x : s) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << x;
	}
	return os << "}";
}

template<class T>
ostream& operator << (ostream& os, const vector<T> v) {
	os << "{";
	bool first = true;
	for (const auto& i : v) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << i;
	}
	return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
	os << "{";
	bool first = true;
	for (const auto& kv : m) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << kv.first << ": " << kv.second;
	}
	return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u,
	const string& hint)
{
	if (t != u) {
		ostringstream os;
		os << "Assertion failed: " << t << " != " << u
			<< " hint: " << hint;
		throw runtime_error(os.str());
	}
}

class TestRunner {
public:
	template <class TestFunc>
	void RunTest(TestFunc func, const string& test_name) {
		try {
			func();
			cerr << test_name << " OK" << endl;
		}
		catch (runtime_error& e) {
			++fail_count;
			cerr << test_name << " fail: " << e.what() << endl;
		}
	}
private:
	int fail_count = 0;
};

inline void Assert(bool b, const string& hint) {
	AssertEqual(b, true, hint);
}

int Sum(int x, int y) {
	return x + y;
}

string Reverse(string s) {

	string my_string = "";
	if (s.size() == 0) {
		return my_string;
	}
	else {
		int k = static_cast<int>(s.size() - 1);
		for (k; k >= 0; k--) {
			my_string += s[k];
		}
	}
	return my_string;
}

void Sort(vector<int>& nums) {
	sort(nums.begin(), nums.end());
}

void SumTest() {
	AssertEqual(Sum(3, 3), 6, "1-1");
	AssertEqual(Sum(0, 0), 0, "1-2");
	AssertEqual(Sum(-5, 5), 0, "1-3");
	AssertEqual(Sum(-10, -6), -16, "1-4");
}

void ReverseTest() {
	AssertEqual(Reverse("abc"), "cba", "1-1");
	AssertEqual(Reverse(""), "", "1-2");
}

void SortTest() {
	vector<int> lhs = { 1, 4, 3, 2 };
	vector<int> rhs = { 1, 2, 3, 4 };
	Sort(lhs);
	AssertEqual(lhs, rhs, "1-1");
}

//int main()
//{
//	TestRunner runner;
//	runner.RunTest(SumTest, "Sum test");
//	runner.RunTest(ReverseTest, "Reverse test");
//	runner.RunTest(SortTest, "Sort test");
//}

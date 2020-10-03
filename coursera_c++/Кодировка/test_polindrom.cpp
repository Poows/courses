#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
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
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
	if (t != u) {
		ostringstream os;
		os << "Assertion failed: " << t << " != " << u;
		if (!hint.empty()) {
			os << " hint: " << hint;
		}
		throw runtime_error(os.str());
	}
}

void Assert(bool b, const string& hint) {
	AssertEqual(b, true, hint);
}

class TestRunner {
public:
	template <class TestFunc>
	void RunTest(TestFunc func, const string& test_name) {
		try {
			func();
			cerr << test_name << " OK" << endl;
		}
		catch (exception& e) {
			++fail_count;
			cerr << test_name << " fail: " << e.what() << endl;
		}
		catch (...) {
			++fail_count;
			cerr << "Unknown exception caught" << endl;
		}
	}

	~TestRunner() {
		if (fail_count > 0) {
			cerr << fail_count << " unit tests failed. Terminate" << endl;
			exit(1);
		}
	}

private:
	int fail_count = 0;
};

bool IsPalindrom(const string& str) {
	for (int i = 0; i < str.size() / 2; ++i) {
		if (str[i] != str[str.size() - i - 1]) {
			return false;
		}
	}
	return true;
}

void FirstTest() {
	AssertEqual(IsPalindrom(""), true, "1-1");
	AssertEqual(IsPalindrom("a"), true, "1-2");
	AssertEqual(IsPalindrom("madam madam"), true, "1-3");
	AssertEqual(IsPalindrom("wasitacaroracatisaw"), true, "1-6");
	AssertEqual(IsPalindrom("wasitacaroracatisaw wasitacaroracatisaw"), true, "1-7");
	AssertEqual(IsPalindrom(" "), true, "1-8");
	AssertEqual(IsPalindrom("1"), true, "1-9");
	AssertEqual(IsPalindrom("  lol  "), true, "1-10");
	AssertEqual(IsPalindrom("     madam     "), true, "1-11");
	AssertEqual(IsPalindrom("l e v e l"), true, "1-12");
	AssertEqual(IsPalindrom(" 1 1 "), true, "1-13");
	AssertEqual(IsPalindrom(" 3 3 3 3  "), false, "1-14");
	AssertEqual(IsPalindrom("777777"), true, "1-15");
	AssertEqual(IsPalindrom("Madam"), false, "1-16");
	AssertEqual(IsPalindrom("_ _ _AbA _ _"), false, "1-17");
	AssertEqual(IsPalindrom("___AAa___"), false, "1-18");
	AssertEqual(IsPalindrom("      "), true, "1-19");
	AssertEqual(IsPalindrom("MadaM"), true, "1-20");
	AssertEqual(IsPalindrom("radam"), false, "1-21");
	AssertEqual(IsPalindrom("baobab"), false, "1-22");
	AssertEqual(IsPalindrom("777778"), false, "1-23");
	AssertEqual(IsPalindrom("а роза упала на лапу азора"), false, "1-24");
	AssertEqual(IsPalindrom("qwertytrewQ"), false, "1-25");
	AssertEqual(IsPalindrom("qwertyTrewq"), false, "1-26");
	AssertEqual(IsPalindrom("qwertytrewq"), true, "1-27");
}

int main() {
	TestRunner runner;
	runner.RunTest(FirstTest, "First test");
	return 0;
}

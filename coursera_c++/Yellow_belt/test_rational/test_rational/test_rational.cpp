#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

class Rational {
public:
	Rational() {
		numerator = 0;
		denominator = 1;
	}
	Rational(int numerator, int denominator) {
		this->numerator = numerator;
		this->denominator = denominator;
		GetCorrectValue(this->numerator, this->denominator);
	}

	void GetCorrectValue(int& numerator, int& denominator) {
		if (numerator == 0) {
			denominator = 1;
		}
		else {
			GCD = GreatestCommonDivisor(numerator, denominator);
			numerator = numerator / GCD;
			denominator = denominator / GCD;

			if (denominator < 0) {
				denominator = -denominator;
				numerator = -numerator;
			}
		}
	}

	int GreatestCommonDivisor(int a, int b) {
		if (b == 0) {
			return a;
		}
		else {
			return GreatestCommonDivisor(b, a % b);
		}
	}

	int Numerator() const {
		return numerator;
	}

	int Denominator() const {
		return denominator;
	}

private:
	int numerator;
	int denominator;
	int GCD = 0;
};

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

void FirstTest() {
	Rational r;
	AssertEqual(r.Numerator(), 0, "1-1");
	AssertEqual(r.Denominator(), 1, "1-2");
}

void SecondTest() {
	Rational r(6, 9);
	AssertEqual(r.Numerator(), 2, "2-1");
	AssertEqual(r.Denominator(), 3, "2-2");
	Rational r2(2, 1);
	AssertEqual(r2.Numerator(), 2, "2-3");
	AssertEqual(r2.Denominator(), 1, "2-4");
	Rational r3(6, 7);
	AssertEqual(r3.Numerator(), 6, "2-5");
	AssertEqual(r3.Denominator(), 7, "2-6");
	Rational r4(5, 4);
	AssertEqual(r4.Numerator(), 5, "2-7");
	AssertEqual(r4.Denominator(), 4, "2-8");
	Rational r5(6, 6);
	AssertEqual(r5.Numerator(), 1, "2-9");
	AssertEqual(r5.Denominator(), 1, "2-10");

}

void ThirdTest() {
	Rational r1(-1, 2);
	AssertEqual(r1.Numerator(), -1, "3-1");
	AssertEqual(r1.Denominator(), 2, "3-2");
	Rational r2(1, -2);
	AssertEqual(r2.Numerator(), -1, "3-3");
	AssertEqual(r2.Denominator(), 2, "3-4");
	Rational r3(4, -6);
	AssertEqual(r3.Numerator(), -2, "3-5");
	AssertEqual(r3.Denominator(), 3, "3-6");
	Rational r4(-4, 6);
	AssertEqual(r4.Numerator(), -2, "3-7");
	AssertEqual(r4.Denominator(), 3, "3-8");
}

void FourthTest() {
	Rational r1(100, 1000);
	AssertEqual(r1.Numerator(), 1, "4-1");
	AssertEqual(r1.Denominator(), 10, "4-2");
	Rational r2(-3, -5);
	AssertEqual(r2.Numerator(), 3, "4-3");
	AssertEqual(r2.Denominator(), 5, "4-4");
	Rational r3(-6, -9);
	AssertEqual(r3.Numerator(), 2, "4-5");
	AssertEqual(r3.Denominator(), 3, "4-6");
}

void FifthTest() {
	Rational r1(0, 1);
	AssertEqual(r1.Numerator(), 0, "5-1");
	AssertEqual(r1.Denominator(), 1, "5-2");
}

int main() {
	TestRunner runner;
	runner.RunTest(FirstTest, "First test");
	runner.RunTest(SecondTest, "Second test");
	runner.RunTest(ThirdTest, "Third test");
	runner.RunTest(FourthTest, "Fourth test");
	runner.RunTest(FifthTest, "Fifth test");
	return 0;
}
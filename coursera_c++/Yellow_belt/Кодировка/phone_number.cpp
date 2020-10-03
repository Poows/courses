#include <sstream>
#include <exception>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include "phone_number.h"

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

inline void Assert(bool b, const string& hint) {
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
		catch (runtime_error& e) {
			++fail_count;
			cerr << test_name << " fail: " << e.what() << endl;
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

PhoneNumber::PhoneNumber(const string& international_number) {
	
	int flag = 0;
	int count_def = 0;
	country_code_ = "";
	city_code_ = "";
	local_number_ = "";

	if (international_number[0] != '+') {
		throw invalid_argument("invalid_argument");
	}

	for (size_t i = 1; i < international_number.size(); i++) {

		if (flag == 2) {
			local_number_ += international_number[i];
		}

		if (flag == 1) {
			if (international_number[i] != '-') {
				city_code_ += international_number[i];
			}
			else {
				count_def++;
				flag = 2;
			}
		}

		if (flag == 0) {
			if (international_number[i] != '-') {
				country_code_ += international_number[i];
			}
			else {
				count_def++;
				flag = 1;
			}
		}
	}

	if (country_code_ == "" || city_code_ == "" || local_number_ == "") {
		throw invalid_argument("invalid_argument");
	}

	if (count_def != 2) {
		throw invalid_argument("invalid_argument");
	}
}

string PhoneNumber::GetCountryCode() const {
	return country_code_;
}

string PhoneNumber::GetCityCode() const {
	return city_code_;
}

string PhoneNumber::GetLocalNumber() const {
	return local_number_;
}

string PhoneNumber::GetInternationalNumber() const {
	return ("+" + country_code_ + "-" + city_code_ + "-" + local_number_);
}

void PhoneNumberTest() {
	PhoneNumber p1("+7-965-3443242");
	AssertEqual(p1.GetCountryCode(), "+7", "1-1");
	AssertEqual(p1.GetCityCode(), "965", "1-2");
	AssertEqual(p1.GetLocalNumber(), "3443242", "1-3");
	AssertEqual(p1.GetInternationalNumber(), "+7-965-3443242", "1-4");
	PhoneNumber p2("+7-495-111-22-33");
	AssertEqual(p2.GetCountryCode(), "+7", "2-1");
	AssertEqual(p2.GetCityCode(), "495", "2-2");
	AssertEqual(p2.GetLocalNumber(), "111-22-33", "2-3");
	AssertEqual(p2.GetInternationalNumber(), "+7-495-111-22-33", "2-4");
	PhoneNumber p3("+323-22-460002");
	AssertEqual(p3.GetCountryCode(), "+323", "3-1");
	AssertEqual(p3.GetCityCode(), "22", "3-2");
	AssertEqual(p3.GetLocalNumber(), "460002", "3-3");
	AssertEqual(p3.GetInternationalNumber(), "+323-22-460002", "3-4");
	PhoneNumber p4("+1-2-coursera-cpp");
	AssertEqual(p4.GetCountryCode(), "+1", "4-1");
	AssertEqual(p4.GetCityCode(), "2", "4-2");
	AssertEqual(p4.GetLocalNumber(), "coursera-cpp", "4-3");
	AssertEqual(p4.GetInternationalNumber(), "+1-2-coursera-cpp", "4-4");
	PhoneNumber p5("+7-1233");
}

//int main()
//{
//	TestRunner runner;
//	runner.RunTest(PhoneNumberTest, "PhoneNumber test");
//}


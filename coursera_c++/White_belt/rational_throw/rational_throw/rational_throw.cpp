// rational_throw.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <numeric>
#include <sstream>

using namespace std;

class Rational {
public:
	Rational() {
		p = 0;
		q = 1;
	}

	Rational(int numerator, int denominator) {
		if (denominator == 0) {
			throw invalid_argument("dividing by zero in constructor");
		}
		
		NOD = gcd(numerator, denominator);
		p = numerator / NOD;
		q = denominator / NOD;
		if (q < 0)
		{
			p = -p;
			q = -q;
		}
	}

	int Numerator() const {
		int numerator = p;

		return numerator;
	}

	int Denominator() const {
		int denominator = q;

		return denominator;
	}

private:
	int p;
	int q;
	int NOD;
};


Rational operator/ (const Rational&& r1, const Rational&& r2) {
	int numerator = r1.Numerator() * r2.Denominator();
	int denominator = r2.Numerator() * r1.Denominator();
	if (denominator == 0) {
		throw domain_error("dividing by zero");
	}
	Rational r3(numerator, denominator);
	return r3;
}

Rational operator/ (const Rational& r1, const Rational& r2) {
	int numerator = r1.Numerator() * r2.Denominator();
	int denominator = r2.Numerator() * r1.Denominator();
	if (denominator == 0) {
		throw domain_error("dividing by zero");
	}
	Rational r3(numerator, denominator);
	return r3;
}

int main() 
{
	try {
		Rational r(1, 0);
		cout << "Doesn't throw in case of zero denominator" << endl;
		return 1;
	}
	catch (invalid_argument& ex) {
		cout << ex.what() << endl;
	}

	try {
		auto x = Rational(1, 2) / Rational(0, 1);
		cout << "Doesn't throw in case of division by zero" << endl;
		return 2;
	}
	catch (domain_error& ex) {
		cout << ex.what() << endl;
	}

	cout << "OK" << endl;
	return 0;
}

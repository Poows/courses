#include <iostream>
#include <string>
using namespace std;

class Rational {
public:

	int p;
	int q;
	int total = 0;
	string s_total;

	Rational() {
		p = 0;
		q = 1;
	}

	Rational(int numerator, int denominator) {
		p = numerator;
		q = denominator;
		total = 0;

		p /= NOD(numerator, denominator);
		q /= NOD(numerator, denominator);

		if (p % q == 0) {
			total = p / q;
		}
		else {
			s_total = p + "/" + q;
		}
	}

	int NOD (int numerator, int denominator) {
		while (numerator > 0 && denominator > 0) {
			if (numerator > denominator) {
				numerator %= denominator;
			}
			else {
				denominator %= numerator;
			}
		}
		return nod = numerator + denominator;
	}

private:
	int nod = 0;
};

Rational operator+ (Rational& r1, Rational& r2) {
	int numerator = r1.p;
	int numerator2 = r2.p;
	int denominator = r1.q;
	if (r1.q == r2.q) {
		Rational r3(r1.p + r2.p, r1.q);
		return r3;
	}
	else {
		numerator = numerator * r2.q;
		numerator2 = numerator2 * r1.q;
		denominator *= r2.q;
		Rational r3(numerator + numerator2, denominator);
		return r3;
	}
}

Rational operator- (Rational& r1, Rational& r2) {
	int numerator = r1.p;
	int numerator2 = r2.p;
	int denominator = r1.q;
	if (r1.q == r2.q) {
		Rational r3(r1.p - r2.p, r1.q);
		return r3;
	}
	else {
		numerator = numerator * r2.q;
		numerator2 = numerator2 * r1.q;
		denominator *= r2.q;
		Rational r3(numerator - numerator2, denominator);
		return r3;
	}
}

Rational operator* (Rational& r1, Rational& r2) {
	int numerator = r1.p;
	int numerator2 = r2.p;
	int denominator = r1.q;
	int denominator2 = r2.q;

	Rational r3(numerator * numerator2, denominator * denominator2);
	return r3;
}

Rational operator/ (Rational& r1, Rational& r2) {
	int numerator = r1.p;
	int numerator2 = r2.p;
	int denominator = r1.q;
	int denominator2 = r2.q;

	Rational r3(numerator * denominator2, denominator * numerator2);
	return r3;
}

bool operator== (const Rational& r1, const Rational& r2) {
	if (r1.total && r2.total == 0) {
		return (r1.s_total == r2.s_total);
	}
	else  return (r1.total == r2.total);
}

//int main() {
//	{
//		Rational a(2, 3);
//		Rational b(4, 3);
//		Rational c = a * b;
//		bool equal = c == Rational(8, 9);
//		if (!equal) {
//			cout << "2/3 * 4/3 != 8/9" << endl;
//			return 1;
//		}
//	}
//
//	{
//		Rational a(5, 4);
//		Rational b(15, 8);
//		Rational c = a / b;
//		bool equal = c == Rational(2, 3);
//		if (!equal) {
//			cout << "5/4 / 15/8 != 2/3" << endl;
//			return 2;
//		}
//	}
//
//	cout << "OK" << endl;
//	return 0;
//}
#include <iostream>
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
		if (numerator == 0) {
			p = 0;
			q = 1;
		}
		else {
			NOD = gcd(numerator, denominator);
			p = numerator / NOD;
			q = denominator / NOD;
			if (p * q < 0) {
				if (q < 0) {
					p = -p;
					q = -q;
				}
			}
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

Rational operator+ (Rational& r1, Rational& r2) {
	int numerator = r1.Numerator() * r2.Denominator() + r2.Numerator() * r1.Denominator();
	int denominator = r1.Denominator() * r2.Denominator();
	Rational r3(numerator, denominator);
	return r3;
}

Rational operator- (Rational& r1, Rational& r2) {
	int numerator = r1.Numerator() * r2.Denominator() - r2.Numerator() * r1.Denominator();
	int denominator = r1.Denominator() * r2.Denominator();
	Rational r3(numerator, denominator);
	return r3;
}

bool operator== (const Rational& r1, const Rational& r2) {
	return (r1.Numerator() == r2.Numerator() && r1.Denominator() == r2.Denominator());
}

Rational operator* (Rational& r1, Rational& r2) {
	int numerator = r1.Numerator() * r2.Numerator();
	int denominator = r1.Denominator() * r2.Denominator();
	Rational r3(numerator, denominator);
	return r3;
}

Rational operator/ (Rational& r1, Rational& r2) {
	int numerator = r1.Numerator() * r2.Denominator();
	int denominator = r2.Numerator() * r1.Denominator();
	Rational r3(numerator, denominator);
	return r3;
}

ostream& operator<< (ostream& stream, const Rational& duration) {
	stream << duration.Numerator() << "/" << duration.Denominator();
	return stream;
}

istream& operator>> (istream& stream, Rational& r) {
	string txt = "";
	string numerator = "";
	string denominator = "";
	int flag = 0;
	stream >> txt;
	if (txt == "") return stream;

	for (int i = 0; i < txt.length(); i++) {
		if (txt[i] >= '0' || txt[i] <= '9') {
			if (flag == 0) {
				numerator += txt[i];
			}
			if (flag == 1) {
				denominator += txt[i];
			}
		}
		if (txt[i] == '/') {
			flag = 1;
		}
	}

	int num = atoi(numerator.c_str());
	int den = atoi(denominator.c_str());

	r = Rational(num, den);
	return stream;
}

int main() 
{
	{
		ostringstream output;
		output << Rational(-6, 8);
		if (output.str() != "-3/4") {
			cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
			return 1;
		}
	}

	{
		istringstream input("5/7");
		Rational r;
		input >> r;
		bool equal = r == Rational(5, 7);
		if (!equal) {
			cout << "5/7 is incorrectly read as " << r << endl;
			return 2;
		}
	}

	{
		istringstream input("5/7 10/8");
		Rational r1, r2;
		input >> r1 >> r2;
		bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
		if (!correct) {
			cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
			return 3;
		}

		input >> r1;
		input >> r2;
		correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
		if (!correct) {
			cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
			return 4;
		}
	}

	cout << "OK" << endl;
	return 0;
}

#include <iostream>
#include <algorithm>
#include <numeric>
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
		/*while (numerator > 0 && denominator > 0) {
			if (numerator > denominator) {
				numerator %= denominator;
			}
			else {
				denominator %= numerator;
			}
		}*/
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

int main() {

	{
		const Rational r(3, 10);
		if (r.Numerator() != 3 || r.Denominator() != 10) {
			cout << "Rational(3, 10) != 3/10" << endl;
			return 1;
		}
	}

	{
		const Rational r(8, 12);
		if (r.Numerator() != 2 || r.Denominator() != 3) {
			cout << "Rational(8, 12) != 2/3" << endl;
			return 2;
		}
	}

	{
		const Rational r(-4, 6);
		if (r.Numerator() != -2 || r.Denominator() != 3) {
			cout << "Rational(-4, 6) != -2/3" << endl;
			return 3;
		}
	}

	{
		const Rational r(4, -6);
		if (r.Numerator() != -2 || r.Denominator() != 3) {
			cout << "Rational(4, -6) != -2/3" << endl;
			return 3;
		}
	}

	{
		const Rational r(0, 15);
		if (r.Numerator() != 0 || r.Denominator() != 1) {
			cout << "Rational(0, 15) != 0/1" << endl;
			return 4;
		}
	}

	{
		const Rational defaultConstructed;
		if (defaultConstructed.Numerator() != 0 || defaultConstructed.Denominator() != 1) {
			cout << "Rational() != 0/1" << endl;
			return 5;
		}
	}

	cout << "OK" << endl;
	return 0;
}

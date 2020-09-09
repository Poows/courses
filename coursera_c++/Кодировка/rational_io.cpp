#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>
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
			if (p < 0) {
				s_total = "-";
				int loc = -p;
				s_total += to_string(loc) + "/" + to_string(q);
			}
			else if (q < 0) {
				s_total = "-";
				int loc = -q;
				s_total += to_string(p) + "/" + to_string(loc);
			}
			else {
				s_total = p + "/" + q;
			}
		}
	}

	int NOD(int numerator, int denominator) {
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

ostream& operator<< (ostream& stream, const Rational& duration) {
	Rational r(duration.p, duration.q);
	stream << r.p << "/" << r.q;
	return stream;
}

istream& operator>> (istream& stream, Rational r) {
	string dur;
	string g;
	int flag = 0;
	stream >> dur;
	for (int i = 0; i < dur.length(); i++) {
		if (dur[i] != ' ') {
			if (dur[i] != '/') {
				g = dur[i];
				istringstream iss(g, istringstream::in);
				int val;
				if (flag % 2 == 0) {
					iss >> r.p;
					flag++;
				}
				else {
					iss >> r.q;
					flag++;
				}
			}
			else {
				continue;
			}
		}
	}
	return stream;
}

bool operator== (const Rational& r1, const Rational& r2) {
	if (r1.total && r2.total == 0) {
		return (r1.s_total == r2.s_total);
	}
	else  return (r1.total == r2.total);
}

//int main() {
//	{
//		ostringstream output;
//		output << Rational(-6, 8);
//		if (output.str() != "-3/4") {
//			cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
//			return 1;
//		}
//	}
//
//	{
//		istringstream input("5/7");
//		Rational r;
//		input >> r;
//		bool equal = r == Rational(5, 7);
//		if (!equal) {
//			cout << "5/7 is incorrectly read as " << r << endl;
//			return 2;
//		}
//	}
//
//	{
//		istringstream input("5/7 10/8");
//		Rational r1, r2;
//		input >> r1 >> r2;
//		bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
//		if (!correct) {
//			cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
//			return 3;
//		}
//
//		input >> r1;
//		input >> r2;
//		correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
//		if (!correct) {
//			cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
//			return 4;
//		}
//	}
//
//	cout << "OK" << endl;
//	return 0;
//}
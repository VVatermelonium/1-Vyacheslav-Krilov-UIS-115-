#include "Rational.h"
Rational::Rational(int a, int b) {
	this->a = a;
	this->b = b;
}

Rational operator+ (const Rational& q1, const Rational& q2) {
	return Rational(q1.a * q2.b + q1.b * q2.a, q1.b * q2.b);
}

Rational operator/ (const Rational& q1, const Rational& q2) {
	return Rational(q1.a * q2.b, q1.b * q2.a);
}

Rational operator- (const Rational& q1, const Rational& q2) {
	return Rational(q1.a * q2.b - q1.b * q2.a, q1.b * q2.b);
}
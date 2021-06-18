#include "Rational.h"

Rational::Rational(const int a, const int b) {
    this->set_a(a);
    this->set_b(b);
}

Rational operator+ (const Rational& q1, const Rational& q2) {
    return Rational(q1.get_a() * q2.get_b() + q1.get_b() * q2.get_a(), q1.get_b() * q2.get_b());
}

Rational operator/ (const Rational& q1, const Rational& q2) {
    return Rational(q1.get_a() * q2.get_b(), q1.get_b() * q2.get_a());
}

Rational operator- (const Rational& q1, const Rational& q2) {
    return Rational(q1.get_a() * q2.get_b() - q1.get_b() * q2.get_a(), q1.get_b() * q2.get_b());
} 

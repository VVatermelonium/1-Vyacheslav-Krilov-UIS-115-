#include "Rational.h"

Rational::Rational(int a, int b) {
#if DEBUG
    cout << "====> Rational::Rational(int a, int b)" << endl;
#endif
    this->set_a(a);
    this->set_b(b);
}

Rational operator+ (const Rational& q1, const Rational& q2) {
#if DEBUG
    cout << "====> Rational operator+ (Rational& q1, Rational& q2)" << endl;
#endif
    return Rational(q1.get_a() * q2.get_b() + q1.get_b() * q2.get_a(), q1.get_b() * q2.get_b());
}

Rational operator/ (const Rational& q1, const Rational& q2) {
#if DEBUG
    cout << "====> Rational operator/ (Rational& q1, Rational& q2)" << endl;
#endif
    return Rational(q1.get_a() * q2.get_b(), q1.get_b() * q2.get_a());
}

Rational operator- (const Rational& q1, const Rational& q2) {
#if DEBUG
    cout << "====> Rational operator- (Rational& q1, Rational& q2)" << endl;
#endif
    return Rational(q1.get_a() * q2.get_b() - q1.get_b() * q2.get_a(), q1.get_b() * q2.get_b());
}
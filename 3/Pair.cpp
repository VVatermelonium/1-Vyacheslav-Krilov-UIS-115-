#include "pair.h"

using namespace std;

Pair::Pair(int a, int b) {
	this->a = a;
	this->b = b;
}

Pair::Pair(void) {
	a = 0;
	b = 0;
}

Pair::~Pair(void) {
}

ostream& operator<< (ostream& out, Pair& p) {
	out << "(" << p.a << ", " << p.b << ")";
	return out;
}

bool Pair::are_equal() {
	return (a == b);
}

int Pair::multiply() {
	return a * b;
}

Pair operator- (const Pair& q1, const Pair& q2) {
	return Pair(q1.a - q1.b, q2.a - q2.b);
}
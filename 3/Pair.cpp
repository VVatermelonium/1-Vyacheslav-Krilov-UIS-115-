#include "pair.h"

using namespace std;

Pair::Pair(int a, int b) {
	this->a = new int(a);
	this->b = new int(b);
}

Pair::Pair() {
	a = nullptr;
	b = nullptr;
}

Pair::Pair(Pair&& var) {
	this->a = var.a;
	this->b = var.b;
	var.a = nullptr;
	var.b = nullptr;
}

Pair::~Pair() {
	delete a;
	delete b;
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
#pragma once
#include "Pair.h"

class Rational : public Pair {
public:
	Rational(int, int);
	friend Rational operator+ (const Rational&, const Rational&);
	friend Rational operator/ (const Rational&, const Rational&);
	friend Rational operator- (const Rational&, const Rational&);
};
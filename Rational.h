#pragma once
#include "Pair.h"

class Rational : public Pair {
public:
	Rational(const int, const int);
	friend Rational operator+ (const Rational&, const Rational&);
	friend Rational operator/ (const Rational&, const Rational&);
	friend Rational operator- (const Rational&, const Rational&);
};
#pragma once
#include "Pair.h"


class Rational : public Pair {
public:
	friend Rational operator+ (const Rational&, const Rational&);
	friend Rational operator/ (const Rational&, const Rational&);
	friend Rational operator- (const Rational&, const Rational&);
	Rational(int, int);
};
#pragma once
#include <iostream>

using namespace std;

class Pair {
public:
	Pair(void);
	Pair(int, int);
	~Pair(void);
	bool are_equal();
	int multiply();
	friend Pair operator- (const Pair&, const Pair&);
	friend ostream& operator<< (ostream& out, Pair& p);
	int a, b;
};




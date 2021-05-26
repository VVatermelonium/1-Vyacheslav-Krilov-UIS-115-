#pragma once
#include <iostream>

using namespace std;

class Pair {
private:
	int* a;
	int* b;
public:
	Pair();
	Pair(int, int);
	Pair(Pair&& var);
	~Pair();
	bool are_equal();
	int multiply();
	friend Pair operator- (const Pair&, const Pair&);
	friend ostream& operator<< (ostream& out, Pair& p);
};




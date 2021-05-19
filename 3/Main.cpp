#include <iostream>
#include "Pair.h"
#include "Rational.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	Pair q(10, 9);
	if (q.are_equal()) 
		cout << "Числа равны" << endl;
	else 
		cout << "Числа не равны" << endl;
	cout << "Произведение полей равно " << q.multiply();
	cout << endl;
	Pair q1(10, 4);
	Pair q2(5, 1);
	Pair q3 = q1 - q2;
	cout << q3 << endl;


	Rational w1(4, 1);
	Rational w2(5, 5);
	Rational w3 = w1 - w2;
	cout << "Разность пар " << w1 << " и " << w2 << " равно " << endl;
	cout << w3 << endl;
	Rational e1(8, 1);
	Rational e2(3, 4);
	cout << "Сумма пар " << e1 << " и " << e2 << " равно " << endl;
	Rational e3 = e1 + e2;
	cout << e3 << endl;
	Rational r1(9, 0);
	Rational r2(3, 3);
	cout << "Частное пар " << r1 << " и " << r2 << " равно " << endl;
	Pair r3 = r1 / r2;
	cout << r3 << endl;
	return 0;
}
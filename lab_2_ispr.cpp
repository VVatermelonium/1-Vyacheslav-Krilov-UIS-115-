#include <iostream>
#include "Pair.h"
#include "Rational.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    Pair var1;
    var1.set_a(1);
    var1.set_b(1);
    cout << "var1: " << var1 << endl;
    Pair var2(5, 3);
    cout << "var2: " << var2 << endl;
    cout << "Проверка на равенство var1 и var2: " << (var1 == var2) << endl;
    cout << "Проверка на равенство var2 и Pair(5, 3)" << endl;
    (var2 == Pair(5, 3)) ? cout << "Равны" << endl : cout << "Не равны" << endl;
    cout << "Проверка операции перемножения полей Pair(2, 2) * Pair(3, 3)" << endl;
    cout << Pair(2, 2) * Pair(3, 3) << endl;
    Pair var3 = var2 - var1;
    cout << "Проверка операции вычитания по формуле: (а, b) - (с, d) = (а - b, с - d)" << endl;
    cout << "var3 = var2 - var1: " << var3 << endl;
    Rational rvar1(1, 1), rvar2(5, 3);
    cout << "Проверка операции сложения (а, b) + (с, d) - (ad + bc, bd)" << endl;
    Rational rvar3 = rvar1 + rvar2;
    cout << rvar1 << " + " << rvar2 << " = " << rvar3 << endl;
    cout << "Проверка операции деления (a, b) / (с, d) - (ad, bc)" << endl;
    rvar3 = rvar1 / rvar2;
    cout << rvar1 << " / " << rvar2 << " = " << rvar3 << endl;
    cout << "Проверка операции вычитания (а, b) - (с, d) = (ad - bc, bd)" << endl;
    rvar3 = rvar1 - rvar2;
    cout << rvar1 << " - " << rvar2 << " = " << rvar3 << endl;

    return 0;
}
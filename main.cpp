#include <iostream>
#include <stdexcept>
#include "Date.h"
#include "EmptyClass.h"
#include "HeirClass.h"
#include "IndepClass.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    Date a(2, 6, 1700);
    Date b(2, 6, 1);
    Date d(11, 6, 2021);
    Date c(2, 6, 2000);
    Date wrong0(0, 0, 0);
    Date wrong1((unsigned)0, (unsigned)2, (unsigned)2);
    Date wrong2((unsigned)2, (unsigned)2, (unsigned)0);
    Date wrong3((unsigned)2, (unsigned)40, (unsigned)2020);
    Date wrong4((unsigned)29, (unsigned)2, (unsigned)2019);
    Date wrong5((unsigned)31, (unsigned)4, (unsigned)2021);
    Date valid6(9, 6, 2021);

    cout << "Проверка из конструктора(int, int, int) Date(0,0,0): " << wrong0 << endl;

    cout << "Проверка високосного года: " << a << " " <<
        a.is_leap_year() << ", " << b << " " <<
        b.is_leap_year() << ", " << c << " " <<
        c.is_leap_year() << ", " << d << " " <<
        d.is_leap_year() << endl;
    cout << "Проверка количества дней с начала года: " << d << " " <<
        d.day_of_year() << endl;
    cout << "Проверка количества дней с начала года: " << c << " " <<
        c.day_of_year() << endl;
    cout << "Проверка правильности даты: " << a << " " << a.is_valid_date() << endl;
    cout << "Проверка правильности даты: " << b << " " << b.is_valid_date() << endl;
    cout << "Проверка правильности даты: " << d << " " << d.is_valid_date() << endl;
    cout << "Проверка правильности даты: " << c << " " << c.is_valid_date() << endl;
    cout << "Проверка правильности даты: " << wrong1 << " " << wrong1.is_valid_date() << endl;

    cout << "День недели: " << a << " " << a.get_day_of_week_simple() << endl;
    cout << "День недели: " << b << " " << b.get_day_of_week_simple() << endl;
    cout << "День недели: " << d << " " << d.get_day_of_week_simple() << endl;
    cout << "День недели: " << c << " " << c.get_day_of_week_simple() << endl;

    cout << "Проверка со спецификацией throw 1" << endl;
    try {
        cout << wrong1 << endl;
        cout << "День недели: " << wrong1.get_day_of_week_simple_throw() << endl;
    }
    catch (...) {
        cout << "Перехвачено исключение throw 1" << endl;
    }

    cout << "Проверка с конкретной спецификацией с подходящим стандартным исключением" << endl;
    try {
        cout << wrong2 << endl;
        cout << wrong2.get_day_of_week_std_logic_throw() << endl;
    }
    catch (logic_error& e) {
        cout << "Перехвачено стандартное исключение типа logic_error: " << e.what() << endl;
    }

    cout << "Проверка с собственным пустым классом" << endl;
    try {
        cout << wrong3 << endl;
        cout << wrong3.get_day_of_week_empty_class_throw() << endl;
    }
    catch (empty_exception) {
        cout << "Перехвачено стандартное исключение типа empty_exception: " << endl;
    }

    cout << "Проверка с независимым классом с полями-параметрами функции: " << endl;
    try {
        cout << wrong4 << endl;
        cout << wrong4.get_day_of_week_indep_class_throw() << endl;
    }
    catch (indep_exception& error) {
        cout << "Перехвачено стандартное исключение типа indep_exception: " << error.what() << endl;
    }

    cout << "Проверка с унаследованным исключением от стандартного: " << endl;
    try {
        cout << wrong5 << endl;
        cout << wrong5.get_day_of_week_heir_std_class_throw() << endl;
    }
    catch (heir_exception& error) {
        cout << "Перехвачено унаследованное исключение heir_exception: " << error.what() << endl;
    }

    try {
        cout << valid6 << endl;
        cout << valid6.get_day_of_week_heir_std_class_throw() << endl;
    }
    catch (heir_exception& error) {
        cout << "Перехвачено унаследованное исключение heir_exception: " << error.what() << endl;
    }
    return 0;
}
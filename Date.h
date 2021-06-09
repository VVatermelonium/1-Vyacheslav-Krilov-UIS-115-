#pragma once
#include <iostream>
#include <string>
#include "EmptyClass.h"
#include "IndepClass.h"
#include "HeirClass.h"

using namespace std;

enum day_of_week { monday, tuesday, wednesday, thursday, friday, saturday, sunday };

class Date {
private:
    unsigned int year;
    unsigned int month;
    unsigned int day;
    enum Month {
        January = 1, February, March,
        April, May, June,
        July, August, September,
        October, November, December
    };
    const unsigned days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    const string week_day_names[7] = { "Воскресенье", "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота" };
public:
    Date();
    // Конструктор день, месяц, год
    Date(unsigned int, unsigned int, unsigned int);
    unsigned int get_year() const;
    unsigned int get_month() const;
    unsigned int get_day() const;
    void set_year(unsigned int);
    void set_month(unsigned int);
    void set_day(unsigned int);
    //Вычисление дня (по счёту) в этом году
    unsigned day_of_year();
    //Проверка правильности введённой даты без спецификации исключений.
    bool is_valid_date();
    //Проверка правильности введённой даты со спецификацией throw.
    bool is_valid_date_throw();
    //Проверка правильности введённой даты с конкретной спецификацией с подходящим стандартным исключением.
    bool is_valid_date_std_logic_throw();
    //Проверка правильности введённой даты со спецификацией с собственным реализованным исключением.
    //(В данный момент, собственное исключение реализованно как пустой класс)
    bool is_valid_date_empty_class_throw();
    //Проверка правильности введённой даты со спецификацией с собственным реализованным исключением.
    //(В данный момент, собственное исключение реализованно как независимый класс с полями-параметрами функции)
    bool is_valid_date_indep_class_throw();
    //Проверка правильности введённой даты со спецификацией с собственным реализованным исключением.
    //(В данный момент, собственное исключение реализованно как наследник от стандартного исключения с полями)
    bool is_valid_date_heir_std_class_throw();
    //Определение наименования дня недели без спецификации исключений.
    string get_day_of_week_simple();
    ///Определение наименования дня недели со спецификацией throw.
    string get_day_of_week_simple_throw();
    //Определение наименования дня недели с конкретной спецификацией с подходящим стандартным исключением.
    string get_day_of_week_std_logic_throw();
    //Определение наименования дня недели со спецификацией с собственным реализованным исключением.
    //(В данный момент, собственное исключение реализованно как пустой класс)
    string get_day_of_week_empty_class_throw();
    //Определение наименования дня недели со спецификацией с собственным реализованным исключением.
    //(В данный момент, собственное исключение реализованно как независимый класс с полями-параметрами функции)
    string get_day_of_week_indep_class_throw();
    //Определение наименования дня недели со спецификацией с собственным реализованным исключением.
    //(В данный момент, собственное исключение реализованно как наследник от стандартного исключения с полями)
    string get_day_of_week_heir_std_class_throw();
    //Проверка, весокосный год или нет.
    bool is_leap_year();
    // Метод отображения
    friend ostream& operator<< (ostream& out, const Date&);
};

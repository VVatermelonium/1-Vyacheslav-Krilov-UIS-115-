#include "ATM.h"
#include <map>
#include <iostream>

// Преобразование числа в строковое представление
std::string transform_number_to_human_readable(unsigned int number, bool thousands, bool millions) {
    std::string result = std::string("");
    std::string first_ten_dict[9] = { "один", "два", "три", "четыре", "пять", "шесть", "семь", "восемь", "девять" };
    std::string first_ten_dict2[9] = { "одна", "две", "три", "четыре", "пять", "шесть", "семь", "восемь", "девять" };
    std::string second_ten_dict[9] = { "одинадцать", "двенадцать", "тринадцать", "четырнадцать", "пятнадцать",
                                      "шестнадцать", "семнадцать", "восемнадцать", "девятнадцать" };
    std::string ten_dict[9] = { "десять", "двадцать", "тридцать", "сорок", "пятьдесят", "шестьдесят",
                               "семьдесят", "восемьдесят", "девяносто" };
    std::string hun_dict[9] = { "сто", "двести", "триста", "четыреста", "пятьсот", "шестьсот",
                               "семьсот", "восемьсот", "девятьсот" };

    if (number >= 1 && number <= 9) {
        if (!thousands) {
            result = first_ten_dict[number - 1];
        }
        else {
            result = first_ten_dict2[number - 1];
        }
    }
    if (number >= 11 && number <= 19) {
        result = second_ten_dict[number - 10 - 1];
    }
    if ((number >= 20 && number <= 99) || (number == 10)) {
        result = ten_dict[number / 10 - 1] + ' ' +
            transform_number_to_human_readable(number % 10, thousands, millions);
    }
    if (number >= 100 && number <= 999) {
        result = hun_dict[number / 100 - 1] + ' ' +
            transform_number_to_human_readable(number % 100, thousands, millions);
    }
    if (number >= 1000 && number <= 999999) {
        std::string th_end = "тысяч";
        unsigned int th = number / 1000;
        if (th % 10 == 1) {
            th_end = "тысяча";
        }
        if (th % 10 >= 2 && th % 10 <= 4) {
            th_end = "тысячи";
        }
        result = transform_number_to_human_readable(number / 1000, true, millions) + ' ' + th_end + " " +
            transform_number_to_human_readable(number % 1000, thousands, millions);
    }
    if (number >= 1000000 && number <= 999999999) {
        std::string mil_end = " миллиона";
        unsigned int mil = number / 1000000;
        if (mil % 10 == 1) {
            mil_end = " миллион";
        }
        if ((mil % 10 >= 5 && mil % 10 <= 9) || mil % 10 <= 0) {
            mil_end = " миллионов";
        }
        result = transform_number_to_human_readable(number / 1000000, thousands, true) + mil_end + " " +
            transform_number_to_human_readable(number % 1000000, thousands, millions);
    }
    // Исправляем проблему двойных пробелов
    std::size_t doubleSpace = result.find("  ");
    while (doubleSpace != std::string::npos)
    {
        result.erase(doubleSpace, 1);
        doubleSpace = result.find("  ");
    }

    return result;
}

void Bankomat::init(int _id) {
    id = _id;
    min_per_day = 100;
    max_per_day = 50000;
    money = { {10, 0}, {50, 0}, {100, 0}, {500, 0}, {1000, 0} };
}

int Bankomat::get_id() const {
    return id;
}

int Bankomat::get_money_left() {
    return money[10] * 10 + money[50] * 50 + money[100] * 100 + money[500] * 500 + money[1000] * 1000;
}

void Bankomat::load(int c10, int c50, int c100, int c500, int c1000) {
    money[10] = c10;
    money[50] = c50;
    money[100] = c100;
    money[500] = c500;
    money[1000] = c1000;
}

void Bankomat::extract(int c10, int c50, int c100, int c500, int c1000) {
    money[10] -= c10;
    money[50] -= c50;
    money[100] -= c100;
    money[500] -= c500;
    money[1000] -= c1000;
}

void Bankomat::load(int count) {
    int thousands = count / 1000;
    int five_thousands = (count % 1000) / 500;
    int hundreds = ((count % 1000) % 500) / 100;
    int five_hundreds = (((count % 1000) % 500) % 100) / 50;
    int ten = ((((count % 1000) % 500) % 100) % 50) / 10;
    load(ten, five_hundreds, hundreds, five_thousands, thousands);
}

bool Bankomat::extract(int count) {
    if (min_per_day <= count && count <= max_per_day) {
        if (count <= get_money_left()) {
            int c10, c50, c100, c500, c1000;
            int thousands = count / 1000;
            int five_thousands = (count % 1000) / 500;
            int hundreds = ((count % 1000) % 500) / 100;
            int five_hundreds = (((count % 1000) % 500) % 100) / 50;
            int ten = ((((count % 1000) % 500) % 100) % 50) / 10;
            if (thousands <= money[1000]) {
                c1000 = thousands;
            }
            else {
                c1000 = money[1000];
                five_thousands += (thousands - c1000) * 2;
            }
            if (five_thousands <= money[500]) {
                c500 = five_thousands;
            }
            else {
                c500 = money[500];
                hundreds += (five_thousands - c500) * 5;
            }
            if (hundreds <= money[100]) {
                c100 = hundreds;
            }
            else {
                c100 = money[100];
                five_hundreds += (hundreds - c100) * 2;
            }
            if (five_hundreds <= money[50]) {
                c50 = five_hundreds;
            }
            else {
                c50 = money[50];
                ten += (five_hundreds - c50) * 5;
            }
            if (ten <= money[10]) {
                c10 = ten;
            }
            else {
                std::cout << "Запрощенная сумма не может быть выдана, поскольку не хватает купюр наминалом 10." <<
                    std::endl;
                return false;
            }
            extract(c10, c50, c100, c500, c1000);
        }
        else {
            std::cout << "Снимаемая сумма больше суммы, находящейся в банкомате. Операция невозможна." << std::endl;
            return false;
        }
    }
    else {
        std::cout << "Снимаемая сумма меньше 100, что недостаточно для минимальной суммы снятия, "
            "или больше 50000, что превышает максимальную сумму снятия. Операция невыполнима " <<
            std::endl;
        return false;
    }
    return true;
}

std::string Bankomat::toString() {
    if (get_money_left() == 0) {
        return std::string("ноль");
    }
    return transform_number_to_human_readable(get_money_left());
}

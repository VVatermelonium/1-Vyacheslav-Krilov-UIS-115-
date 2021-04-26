#pragma once
#include <map>
#include <iostream>

// ѕреобразование числа в строковое представление
std::string transform_number_to_human_readable(unsigned int number, bool thousands = false, bool millions = false);

class Bankomat {
private:
    int id;
    int min_per_day;
    int max_per_day;
    std::map<int, int> money;

public:
    void init(int _id);
    int get_id() const;
    int get_money_left();
    void load(int c10, int c50, int c100, int c500, int c1000);
    void extract(int c10, int c50, int c100, int c500, int c1000);
    void load(int count);
    bool extract(int count);
    std::string toString();
};


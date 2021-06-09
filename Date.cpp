#include "Date.h" 

Date::Date() {
    year = 0;
    month = 1;
    day = 1;
}

//Превращение обычного int, в int, который не может быть отрицательным.
Date::Date(unsigned int _day, unsigned int _month, unsigned int _year) {
    day = _day;
    month = _month;
    year = _year;
}


bool Date::is_leap_year() {
    return !(this->year % 4);
}


bool Date::is_valid_date() {
    //Год не может быть нулевым.
    if (this->year == 0)
        return false;
    //В году 12 месяцев, 13 или 0 и т.д. нет.
    if (this->month < 1 || this->month > 12)
        return false;
    //Нулевого дня нет.
    if (this->day < 1)
        return false;
    //Правильность дней в феврале с учётом возможной весокосности года.
    if (this->month == Month::February && this->day > 28 + is_leap_year())
        return false;
    //Проверка количества дней в месяце.
    if (this->day > days[this->month - 1])
        return false;
    return true;
}


bool Date::is_valid_date_throw() {
    if (this->year == 0)
        throw 1;
    if (this->month < 1 || this->month > 12)
        throw 1;
    if (this->day < 1)
        throw 1;
    if (this->month == Month::February && this->day > (28 + is_leap_year()))
        throw 1;
    if (this->day > days[this->month - 1])
        throw 1;
    return true;
}


bool Date::is_valid_date_std_logic_throw() {
    if (this->year == 0)
        throw logic_error("Год не может быть нулевым.");
    if (this->month < 1 || this->month > 12)
        throw logic_error("Допустимый диапазон месяцев в году от 1 до 12.");
    if (this->day < 1)
        throw logic_error("День не может быть нулевым.");
    if (this->month == Month::February && this->day > (28 + is_leap_year()))
        throw logic_error("Для данного года введено неправильное количество дней в феврале.");
    if (this->day > days[this->month - 1])
        throw logic_error("Не правильно указанно кол-во дней в данном месяце.");
    return true;
}


bool Date::is_valid_date_empty_class_throw() {
    if (this->year == 0)
        throw empty_exception();
    if (this->month < 1 || this->month > 12)
        throw empty_exception();
    if (this->day < 1)
        throw empty_exception();
    if (this->month == Month::February && this->day > (28 + is_leap_year()))
        throw empty_exception();
    if (this->day > days[this->month - 1])
        throw empty_exception();
    return true;
}


bool Date::is_valid_date_indep_class_throw() {
    if (this->year == 0)
        throw indep_exception("Год не может быть нулевым.");
    if (this->month < 1 || this->month > 12)
        throw indep_exception("Допустимый диапазон месяцев в году от 1 до 12.");
    if (this->day < 1)
        throw indep_exception("День не может быть нулевым.");
    if (this->month == Month::February && this->day > (28 + is_leap_year()))
        throw indep_exception("Для данного года введено неправильное количество дней в феврале.");
    if (this->day > days[this->month - 1])
        throw indep_exception("Не правильно указанно кол-во дней в данном месяце.");
    return true;
}


bool Date::is_valid_date_heir_std_class_throw() {
    if (this->year == 0)
        throw heir_exception("Год не может быть нулевым.");
    if (this->month < 1 || this->month > 12)
        throw heir_exception("Допустимый диапазон месяцев в году от 1 до 12.");
    if (this->day < 1)
        throw heir_exception("День не может быть нулевым.");
    if (this->month == Month::February && this->day > (28 + is_leap_year()))
        throw heir_exception("Для данного года введено неправильное количество дней в феврале.");
    if (this->day > days[this->month - 1])
        throw heir_exception("Не правильно указанно кол-во дней в данном месяце.");
    return true;
}


string Date::get_day_of_week_simple() {
    string result = "Плохая дата";
    if (is_valid_date()) {
        unsigned days = day_of_year();
        if (get_year() > 1)
            days += (get_year() - 1) * 365 + (get_year() - 1) / 4 - 1;
        result = week_day_names[days % 7];
    }
    return result;
}


string Date::get_day_of_week_simple_throw() {
    string result = "";
    if (is_valid_date_throw()) {
        unsigned days = day_of_year();
        if (get_year() > 5)
            days += (get_year() - 1) * 365 + (get_year() - 1) / 4 - 1;
        result = week_day_names[days % 7];
    }
    return result;
}


string Date::get_day_of_week_std_logic_throw() {
    string result = "";
    if (is_valid_date_std_logic_throw()) {
        unsigned days = day_of_year();
        if (get_year() > 5)
            days += (get_year() - 1) * 365 + (get_year() - 1) / 4 - 1;
        result = week_day_names[days % 7];
    }
    return result;
}


string Date::get_day_of_week_empty_class_throw() {
    string result = "";
    if (is_valid_date_empty_class_throw()) {
        unsigned days = day_of_year();
        if (get_year() > 5)
            days += (get_year() - 1) * 365 + (get_year() - 1) / 4 - 1;
        result = week_day_names[days % 7];
    }
    return result;
}


string Date::get_day_of_week_indep_class_throw() {
    string result = "";
    if (is_valid_date_indep_class_throw()) {
        unsigned days = day_of_year();
        if (get_year() > 5)
            days += (get_year() - 1) * 365 + (get_year() - 1) / 4 - 1;
        result = week_day_names[days % 7];
    }
    return result;
}


string Date::get_day_of_week_heir_std_class_throw() {
    string result = "";
    if (is_valid_date_heir_std_class_throw()) {
        unsigned days = day_of_year();
        if (get_year() > 5)
            days += (get_year() - 1) * 365 + (get_year() - 1) / 4 - 1;
        result = week_day_names[days % 7];
    }
    return result;
}


unsigned Date::day_of_year() {
    unsigned year_days = 0;
    for (unsigned i = 0; i < this->month - 1; i++)
        year_days += days[i];
    if (this->month > Month::February && is_leap_year())
        year_days++;
    return year_days + this->day;
}

unsigned int Date::get_year() const {
    return year;
}

unsigned int Date::get_month() const {
    return month;
}

unsigned int Date::get_day() const {
    return day;
}

void Date::set_year(unsigned int _year) {
    year = _year;
}

void Date::set_month(unsigned int _month) {
    month = _month;
}

void Date::set_day(unsigned int _day) {
    day = _day;
}

ostream& operator<<(ostream& out, const Date& src) {
    out.fill('0');
    out.width(2);
    out << (src.get_day()) << string("-");
    out.width(2);
    out << to_string(src.get_month()) << string("-");
    out.width(4);
    out << to_string(src.get_year());
    return out;
}
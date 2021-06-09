#pragma once
#include <iostream>
using namespace std;
//Независимый класс с полями-параметрами функции
class indep_exception {
private:
    string error;
public:
    indep_exception(string _err) {
        error = _err;
    }
    string what() {
        return error;
    };
};
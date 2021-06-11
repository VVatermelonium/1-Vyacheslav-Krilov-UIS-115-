#pragma once
#include <iostream>
#include "Date.h"

//Класс-наследник от стандартного исключения с полями.
class heir_exception : public exception {
public:
    heir_exception(char const* const _Message) noexcept
        : exception(_Message, 1)
    {
    }
};
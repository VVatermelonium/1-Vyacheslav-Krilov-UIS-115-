#pragma once
#include <iostream>

using namespace std;

class Pair
{
private:
	int* a;
	int* b;
public:
	// Конструктор по-умолчанию
	Pair();
	// Конструктор с параметрами
	Pair(const int, const int);
	// Конструктор перемещения
	Pair(Pair&&) noexcept;
	// Конструктор копирования
	Pair(const Pair&);
	// Перемещающее присваивание
	Pair& operator= (Pair&& src);
	// Деструктор
	~Pair();
	// Метод получения a
	int get_a() const;
	// Метод получения b
	int get_b() const;
	// Получение адреса a
	int* get_ptr_a() const;
	// Получение адреса b
	int* get_ptr_b() const;
	// Метод установки a
	void set_a(int);
	// Метод установки b
	void set_b(int);
	// Метод установки адреса a
	void set_ptr_a(int*);
	// Метод установки адреса b
	void set_ptr_b(int*);
	// Операция проверки на равенство
	bool operator== (const Pair&) const;
	// Операция перемножения полей Pair(ac, bd)
	friend Pair operator* (Pair, Pair);
	// Метод отображения
	friend ostream& operator<< (ostream& out, const Pair&);
	// Операция вычитания пар по формуле(а, b) - (с, d) = (а - b, с - d)
	friend Pair operator- (Pair, Pair);
};
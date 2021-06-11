#pragma once
#include <cmath>
#include <limits>
class Point
{
private:
	/**
	\brief координата x
	*/
	double x;
	/**
	\brief координата y
	*/
	double y;
public:
	/**
	\brief	конструктор с параметрами
	* \param координата x
	* \param координата y
	*/
	explicit Point(const double x, const double y);
	/**
	\brief	конструктор по умолчанию
	*/
	Point();

	/**
	\brief	деструктор по умолчанию
	*/
	~Point() = default;

	/**
	\brief	конструктор копирования по умолчанию
	*/
	Point(const  Point&) = default;

	/**
	\brief	конструктор присвоения по умолчанию
	*/
	Point& operator=(const  Point&) = default;

	/**
	\brief	конструктор перемещения
	*/
	Point(Point&& other) = default;

	/**
	\brief	сеттер для перемещения по оси x
	*/
	void set_x(double move_x);

	/**
	\brief	сеттер для перемещения по оси x
	*/
	void set_y(double move_y);

	/**
	\brief	расстояние до 0
	*/
	double get_distanse_to_0()const;

	/**
	\brief	расстояние между двумя точками
	*/
	double get_distanse_between_two_points(const Point& other);

	/**
	\brief	перевод в полярную систему координат (расстояние до точки идёт в x, угол фи идёт в y)
	*/
	Point get_polar()const;

	/**
	\brief	равны ли точки
	*/
	bool are_equal(const Point& other);
};


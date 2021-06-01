#pragma once
#include "figure.h"

//класс фигуры эллипс
class ellips : public figure
{
private:
	//длинна полуоси А
	double halfA;
	//длинна полуоси В
	double halfB;
public:
	//конструктор полуось А, полуось В
	ellips(double, double);
	//P = 2 * пи * корень((полуось А^2 + полуось Б^2) / 2)
	double perim() override;
	//S = Пи * полуось А * полуось Б
	double plosh() override;
};

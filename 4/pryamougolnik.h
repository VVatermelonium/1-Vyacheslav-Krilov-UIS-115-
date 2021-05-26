#pragma once
#include "figure.h"

//класс фигуры прямоугольник
class pryamougolnik : public figure
{
private:
	//сторона А
	double sideA;
	//сторона В
	double sideB;
public:
	//конструктор сторона А, сторона В
	pryamougolnik(double, double);
	//P = 2 * (сторона А + сторона В)  
	double perim() override;
	//S = сторона А * сторона В
	double plosh() override;
};


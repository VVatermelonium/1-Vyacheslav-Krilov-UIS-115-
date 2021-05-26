#pragma once
#include "figure.h"

//класс фигуры ромб
class romb : public figure
{
private:
	//сторона
	double sidelen;
	//острый угол
	double corner;
public:
	//конструктор сторона, острый угол
	romb(double, double);
	//P = сторона * 4
	double perim() override;
	//S = сторона * сторона * синус острого угла
	double plosh() override;
};


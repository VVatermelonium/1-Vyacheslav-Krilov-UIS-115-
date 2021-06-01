#pragma once
#include "figure.h"

//класс фигуры ромб
class rombus : public figure
{
private:
	//сторона
	double sidelen;
	//острый угол
	double corner;
public:
	//конструктор сторона, острый угол
	rombus(double, double);
	//P = сторона * 4
	double perim() override;
	//S = сторона * сторона * синус острого угла
	double plosh() override;
};


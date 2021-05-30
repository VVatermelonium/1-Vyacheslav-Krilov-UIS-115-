#pragma once
//чисто виртуальный класс figure
class figure
{
public:
	//вычисление периметра
	virtual double perim() = 0;
	//вычисление площади
	virtual double plosh() = 0;
};


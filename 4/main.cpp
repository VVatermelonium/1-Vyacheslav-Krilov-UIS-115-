#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include "figure.h"
#include "romb.h"
#include "pryamougolnik.h"
#include "ellips.h"

using namespace std;

int main() {
	//русский текст
	setlocale(LC_ALL, "Russian");
	int choice;
	//выбор фигуры
	cout << "выберите фигуру:" << endl;
	cout << "1-ромб, 2-прямоугольник, 3-эллипс" << endl;
	cin >> choice;
	figure *f = nullptr;
	//создаём объект ромб
	if (choice == 1) {
		cout << "на данный момент, ромб имеет сторону 5 и угол 90 градусов " << endl;
		f = new romb(5, M_PI/2);
	}
	//создаём объект прямоугольник
	if (choice == 2) {
		cout << "на данный момент, прямоугольник имеет стороны 2 и 5 " << endl;
		f = new pryamougolnik(2, 5);
	}
	//создаём объект эллипс
	if (choice == 3) {
		cout << "на данный момент, эллипс имеет полуоси 0.5 и 0.5 " << endl;
		f = new ellips(0.5, 0.5);
	}
	//подсчёт и вывод площади и периметра выбранной фигуры
	cout << "площадь выбранной фигуры: " << f->plosh() << endl;
	cout << "периметр выбранной фигуры: " << f->perim() << endl;
	delete f;
	return 0;
}
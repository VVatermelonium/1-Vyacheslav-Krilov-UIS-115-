#include "rectangle.h"

rectangle::rectangle(double A, double B) {
	sideA = A;
	sideB = B;
}

double rectangle::perim() {
	return 2 * (sideA + sideB);
}

double rectangle::plosh() {
	return sideA * sideB;
}

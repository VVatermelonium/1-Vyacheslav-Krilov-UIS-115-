#include "pryamougolnik.h"

pryamougolnik::pryamougolnik(double A, double B) {
	sideA = A;
	sideB = B;
}

double pryamougolnik::perim() {
	return 2 * (sideA + sideB);
}

double pryamougolnik::plosh() {
	return sideA * sideB;
}

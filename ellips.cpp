#define _USE_MATH_DEFINES
#include "ellips.h"
#include <math.h>

ellips::ellips(double A, double B) {
	halfA = A;
	halfB = B;
}

double ellips::perim() {
	return 2 * M_PI * sqrt((halfA * halfA + halfB * halfB) / 2);
}

double ellips::plosh() {
	return M_PI * halfA * halfB;
}

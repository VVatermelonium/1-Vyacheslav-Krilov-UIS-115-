#include "romb.h"
#include <cmath>

rombus::rombus(double s, double c) {
	sidelen = s;
	corner = c;
}

double rombus::perim() {
	return 4 * sidelen;
}

double rombus::plosh() {
	return sidelen * sidelen * sin(corner);
}

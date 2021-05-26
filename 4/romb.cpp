#include "romb.h"
#include <cmath>

romb::romb(double s, double c) {
	sidelen = s;
	corner = c;
}

double romb::perim() {
	return 4 * sidelen;
}

double romb::plosh() {
	return sidelen * sidelen * sin(corner);
}

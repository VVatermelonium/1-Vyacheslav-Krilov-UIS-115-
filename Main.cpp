#include <iostream>
#include "Point.h"

int main()
{
	Point a(1, 1);
	Point b(1, 1);
	std::cout << a.get_distanse_to_0() << std::endl;
	std::cout << b.get_distanse_to_0() << std::endl;
	std::cout << a.get_distanse_to_0() << std::endl;
}
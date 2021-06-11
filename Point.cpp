#include "Point.h"

Point::Point(const double x, const double y)
{
	this->x = x;
	this->y = y;

}

Point::Point()
{
	this->x = 0;
	this->y = 0;
}

void Point::set_x(double move_x)
{
	this->x = this->x + move_x;
}

void Point::set_y(double move_y)
{
	this->y = this->y + move_y;
}

double Point::get_distanse_to_0()const
{
	return abs(sqrt(this->x * this->x + this->y * this->y));
}

double Point::get_distanse_between_two_points(const Point& other)
{
	return abs(sqrt((other.x - this->x) * (other.x - this->x) + (this->y - other.y) * (this->y - other.y)));
}

Point Point::get_polar() const
{
	return Point(sqrt(this->x * this->x + this->y * this->y), atan(x / y));
}

bool Point::are_equal(const Point& other)
{
	return ((this->x - other.x) <= std::numeric_limits<double>::epsilon() && (this->y - other.y) <= std::numeric_limits<double>::epsilon());
}

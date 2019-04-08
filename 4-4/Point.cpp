#include "Point.h"

Point Point::operator+=(const Point ref)
	{
		this->x += ref.get_x();
		this->y += ref.get_y();
		return *this;
	}

bool operator==(const Point p1, const Point p2)
{
	if(p1.get_x() == p2.get_x() && p1.get_y() == p2.get_y())
		return true;
	else
		return false;
}

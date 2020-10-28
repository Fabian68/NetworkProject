#pragma once

#include "Point.h"
#include <vector>



class Hexagon
{
public :
	Hexagon(const Point& center, double radius);

	Point getUp() const;

	Point getUpRight() const;

	Point getDownRight() const;

	Point getDown() const;

	Point getDownLeft() const;

	Point getUpLeft() const;

	Point operator[](int i)const;
	

private :
	std::vector<Point> _listPoint;
	static constexpr double const& PI = 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270193852110555964462294895493038196;
	double _radius;
};

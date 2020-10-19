#ifndef HEXAGON_H
#define HEXAGON_H

#include "Point.h"

class Hexagon
{
public :
	Hexagon(const Point& upLeft, const Point& upRight, const Point& left, const Point& right, const Point& downLeft, const Point& downRight);
	Point getUpLeft() const;
	Point getUpRight() const;
	Point getLeft() const;
	Point getRight() const;
	Point getDownLeft() const;
	Point getDownRight() const;


private :
	Point _upLeft;
	Point _upRight;
	Point _left;
	Point _right;
	Point _downLeft;
	Point _downRight;
};

#endif
#include "Hexagon.h"

Hexagon::Hexagon(const Point& upLeft, const Point& upRight, const Point& left, const Point& right, const Point& downLeft, const Point& downRight)
	: _upLeft{upLeft}, _upRight{upRight}, _left{left}, _right{right}, _downLeft{downLeft}, _downRight{downRight}
{}

Point Hexagon::getUpLeft() const
{
	return _upLeft;
}

Point Hexagon::getUpRight() const
{
	return _upRight;
}

Point Hexagon::getLeft() const
{
	return _left;
}

Point Hexagon::getRight() const
{
	return _right;
}

Point Hexagon::getDownLeft() const
{
	return _downLeft;
}

Point Hexagon::getDownRight() const
{
	return _downRight;
}
#include "Hexagon.h"
#include <algorithm>


Hexagon::Hexagon(const Point& center, double radius, std::vector<double> color) : _radius{radius}
{	
	_color = color;
	double numPoints = 6.0;
	_listPoint.reserve(static_cast<int> (numPoints));
	//radian
	double angle = 2.0* PI / numPoints;
	//double angle = (PI/180.0)*60;
	double centerX = center.getX();
	double centerY = center.getY();

	double x, y;

	//_listPoint.resize(numPoints);

	//construction des points dans le sens anti-trigonométrique en commencant par le point du haut
	for (double i = 0; i < numPoints; i+=1.0)
	{
		x = centerX + radius * sin(i * angle);
		y = centerY + radius * cos(i * angle);
		Point  P =  Point(x, y);
		_listPoint.push_back(P);
	}
}

Point Hexagon::getUp() const
{
	return _listPoint[0];
}

Point Hexagon::getUpRight() const
{
	return _listPoint[1];
}

Point Hexagon::getDownRight() const
{
	return _listPoint[2];
}

Point Hexagon::getDown() const
{
	return _listPoint[3];
}

Point Hexagon::getDownLeft() const
{
	return _listPoint[4];
}

Point Hexagon::getUpLeft() const
{
	return _listPoint[5];
}

Point  Hexagon::operator[](int i)const 
{
	return _listPoint[i];
}

std::vector<double> Hexagon::getColor()
{
	return _color;
}

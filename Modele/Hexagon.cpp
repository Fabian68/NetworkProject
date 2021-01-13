#include "Hexagon.h"
#include <algorithm>


Hexagon::Hexagon(const Point& center, double radius, std::vector<double> color,double transparance) : _radius{radius}
{	

	// http://www.nongnu.org/pyformex/doc-1.0/ref/opengl.colors.html#module-opengl.colors
	// conversions couleurs opengl dans les deux sens
	_color = color;
	_transparance = transparance;
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

std::vector<double> Hexagon::getColor()const
{
	return _color;
}

void Hexagon::setColor(std::vector<double> color)
{
	_color = color;
}

double Hexagon::gettransparance()const
{
	return _transparance;
}

void Hexagon::settransparance(double transparance)
{
	_transparance = transparance;
}

bool Hexagon::contains(const Point& P) const
{
	bool test = false;
	double yMax = getUp().getY();
	double yMin = getDown().getY();

	double xMin = getUpLeft().getX();
	double xMax = getUpRight().getX();

	double X = P.getX();
	double Y = P.getY();
	if ((X <xMin || X > xMax) || (Y <yMin || Y > yMax)) {

	}
	else if (X >= getUpLeft().getX() && X <= getUpRight().getX()) {
		if (Y > getUpLeft().getY()) {
			double distanceY = getUpLeft().getY() - getUp().getY();
			double distanceX = getUp().getX() - getUpLeft().getX();
			double coefictienDroite = distanceY * getUpLeft().getX() + distanceX * getUpLeft().getY();


			double distanceY2 = getUpRight().getY() - getUp().getY();
			double distanceX2 = getUp().getX() - getUpRight().getX();
			double coefictienDroite2 = distanceY2 * getUpRight().getX() + distanceX2 * getUpRight().getY();


			double coeficienDroitePoint = distanceY * P.getX() + distanceX * P.getY();
			double coeficienDroitePoint2 = distanceY2 * P.getX() + distanceX2 * P.getY();

			test = coeficienDroitePoint <= coefictienDroite && coeficienDroitePoint2 >= coefictienDroite2;
		}
		else if (Y < getDownLeft().getY()) {
			double distanceY = getDownLeft().getY() - getDown().getY();
			double distanceX = getDown().getX() - getDownLeft().getX();
			double coefictienDroite = distanceY * getDownLeft().getX() + distanceX * getDownLeft().getY();


			double distanceY2 = getDownRight().getY() - getDown().getY();
			double distanceX2 = getDown().getX() - getDownRight().getX();
			double coefictienDroite2 = distanceY2 * getDownRight().getX() + distanceX2 * getDownRight().getY();


			double coeficienDroitePoint = distanceY * P.getX() + distanceX * P.getY();
			double coeficienDroitePoint2 = distanceY2 * P.getX() + distanceX2 * P.getY();

			test = coeficienDroitePoint >= coefictienDroite && coeficienDroitePoint2 <= coefictienDroite2;
		}
		else {
			test = true;
		}

	}
	return test;
}


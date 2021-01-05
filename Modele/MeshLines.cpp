#include "MeshLines.h"

MeshLines::MeshLines(const Point& centerFirst, double radius, int size) : _size{ size }
{
    _line.reserve(size);

    Point Curent(centerFirst.getX(), centerFirst.getY());
    double xCenter = centerFirst.getX();
    double yCenter = centerFirst.getY();
    _line.push_back(Hexagon(Point(xCenter, yCenter), radius));
    double diff = _line[0][1].getX() - xCenter;
    xCenter += 2 * diff;
    for (int i = 1;i < size;i++,xCenter+=(2*diff)) {
        _line.push_back(Hexagon(Point(xCenter, yCenter), radius));
    }
}

Hexagon MeshLines::operator[](int i) const
{
    return _line[i];
}

int MeshLines::getSize() const
{
    return _size;
}

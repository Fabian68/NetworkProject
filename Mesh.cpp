#include "Mesh.h"



Mesh::Mesh(const Point& FirstCenter, double radius, int lineSize, int colSize) : _colSize{colSize}
{
	MeshLines line1 = MeshLines(FirstCenter, radius, lineSize);
	_column.reserve(colSize);
	_column.push_back(line1);

	double xImpair = line1[0].getUpRight().getX();
	double xPair = FirstCenter.getX();

	double yPair = FirstCenter.getY()+3*radius;
	double yImpair = line1[0].getUpRight().getY()+radius;

	for (int i = 1;i < colSize;i++) {
		if (i % 2 == 0) {
			_column.push_back(MeshLines(Point(xPair, yPair), radius, lineSize));
			yPair += 3 * radius;
		}
		else {
			_column.push_back(MeshLines(Point(xImpair, yImpair), radius, lineSize));
			yImpair += 3 * radius;
		}
	}

}

MeshLines Mesh::operator[](int i) const
{
	return _column[i];
}

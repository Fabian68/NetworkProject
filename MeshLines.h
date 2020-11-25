#pragma once
#include "Hexagon.h"
class MeshLines
{
public:
	MeshLines(const Point& centerFirst,double radius,int size);

	Hexagon operator[](int i)const;
	int getSize()const;
private:
	std::vector<Hexagon> _line;
	int _size;
};


#pragma once
#include "MeshLines.h"

class Mesh
{
public :
	Mesh(const Point & FirstCenter,double radius,int lineSize,int colSize);
	Mesh();
	int getColSize()const;
	MeshLines operator[](int i )const;
	std::vector<Hexagon> getHexagons();
	void getHexagons(std::vector<Hexagon>& Hexagons);
private :
	int _colSize;
	int _lineSize;
	std::vector<MeshLines> _column;
};


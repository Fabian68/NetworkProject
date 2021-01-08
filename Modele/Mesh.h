#pragma once
#include "MeshLines.h"

class Mesh
{
public :
	Mesh(const Point & FirstCenter,double radius,int lineSize,int colSize);
	Mesh();
	MeshLines operator[](int i )const;
private :
	int _colSize;
	std::vector<MeshLines> _column;
};


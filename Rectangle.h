#pragma once
#include "Polygon.h"
class My_Rectangle : public My_Polygon
{
	//	char* type;
	int fillColor = -1;

public:
	My_Rectangle();
	My_Rectangle(double x1, double y1, double x2, double y2, int c = 1);
	~My_Rectangle();
	void fill(int, int, int, COLORREF);

	void draw();
	bool contains(Point p);
	//	void fill(int color);
	void erase();
};

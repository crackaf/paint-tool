#pragma once
#include "Shape.h"
class My_Polygon : public Shape
{
public:
	My_Polygon();
	My_Polygon(double, double, int = 1);
	virtual ~My_Polygon();
	void draw();
	//	void fill();
	bool contains(Point p);
	//	void fill(int color);
	bool check_end();
	void addPoint(double, double);

protected:
	int fillColor;
	//	char* type;
public:
	//	void erase();
	virtual void erase();
	void fill(int, int, int, COLORREF);
};

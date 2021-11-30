#pragma once
#include "OpenShape.h"
class Line : public OpenShape
{
	//	char* type;
public:
	Line();
	Line(double, double, double, double, int = 1);
	~Line();
	void draw();
	bool contains(Point p);
	//	void changeColor();
	void changeColor(int color);
	void erase();
	void fill(int, int, int, COLORREF);
};

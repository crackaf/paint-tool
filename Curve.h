#pragma once
#include "OpenShape.h"
class Curve : public OpenShape
{
	//	char* type;
public:
	Curve();
	Curve(int, int, int = 1);
	~Curve();
	void draw();
	bool contains(Point p);
	void changeColor(int color);
	bool check_end();
	void fill(int, int, int, COLORREF);
	void erase();
};

#pragma once
#include "Shape.h"
class Circle : public Shape
{
public:
	Circle(void);
	Circle(double x1, double y1, double x2, double y2, int _color = 1);
	~Circle();
	//	virtual void draw() = 0;
	//	virtual bool contains(Point p);
	void draw();
	void fill(int, int, int, COLORREF);
	bool contains(Point p);
	void erase();
	void serialization();
	//	void fill(int x, int y, int color, int bck_color);
private:
	int fillColor;
	double radius;
	//	char* type;
};

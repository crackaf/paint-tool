#pragma once
#include "Shape.h"
class OpenShape : public Shape
{
	//	char* type;
public:
	OpenShape();
	OpenShape(int, int, int = 1);
	virtual ~OpenShape();
	//	virtual void changeColor(int c) = 0;
	virtual void changeColor(int color) = 0;
	//void fill(int, int, int, COLORREF);
protected:
	//	int fillColor;
	bool style;

public:
	virtual void erase();
};

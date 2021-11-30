#pragma once
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Polygon.h"
#include "Text.h"
#include "OpenShape.h"
#include "Curve.h"
#include "Line.h"
//#include "GP142.H"
//#include "GP142LIB.H"
#include <fstream>
//#include <cstdio>

#define linem 1
#define rectanglem 2
#define polygonm 3
#define circlem 4
#define curvem 5
#define textm 6
#define fillm 7

class Paint
{
private:
	//void (Paint::*fptr)(void);
	//void (*fptr)(void);
	int color;
	vector<Shape *> allShapes;
	vector<Shape *> Menu;

public:
	Paint();

	void OnStart();
	void openMenu();
	bool check_points(int x, int y);

	void functions(int);
	void line();
	void rectangle();
	void polygon();
	void circle();
	void curve();
	void text();
	void fill();

	void fill(int x, int y, int color, COLORREF bck_color);

	~Paint();
};

class PrintPaint
{
};

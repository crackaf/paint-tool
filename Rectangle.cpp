#include "Rectangle.h"

My_Rectangle::My_Rectangle()
{
	char name[] = "My_Rectangle";
	type = new char[strlen(name) + 1];
	strcpy_s(type, strlen(name) + 1, name);
}

My_Rectangle::My_Rectangle(double x1, double y1, double x2, double y2, int c)
		: My_Polygon(x1, y1, c)
{
	char name[] = "My_Rectangle";
	type = new char[strlen(name) + 1];
	strcpy_s(type, strlen(name) + 1, name);
	addPoint(x2, y2);
}

My_Rectangle::~My_Rectangle()
{
}

void My_Rectangle::fill(int x, int y, int c, COLORREF bck)
{
	fillColor = c;
	Shape::fill(x, y, c, bck);
}

void My_Rectangle::draw()
{
	GP142_lineXY(color, points[0].x, points[0].y, points[0].x, points[1].y, 2);
	GP142_lineXY(color, points[0].x, points[0].y, points[1].x, points[0].y, 2);
	GP142_lineXY(color, points[1].x, points[1].y, points[0].x, points[1].y, 2);
	GP142_lineXY(color, points[1].x, points[1].y, points[1].x, points[0].y, 2);
	//GP142_pixelXY(GREEN, points[0].x, points[0].y);
}

bool My_Rectangle::contains(Point p)
{
	if (((points[0].x < p.x && p.x < points[1].x) || (points[1].x < p.x && p.x < points[0].x)) &&
			((points[0].y < p.y && p.y < points[1].y) || (points[1].y < p.y && p.y < points[0].y)))
		/*if (((points[0].x < p.y && p.y < points[1].y) || (points[1].y < p.y && p.y < points[0].y)) &&
		((points[0].x < p.x && p.x < points[1].x) || (points[1].x < p.x && p.x < points[0].x)))*/
		return true;
	else
		return false;
}

//void My_Rectangle::fill(int color)
//{
//	// TODO: Add your implementation code here.
//}

void My_Rectangle::erase()
{

	GP142_rectangleXY(BLACK, points[0].x, points[0].y, points[1].x, points[1].y, 0);
	// TODO: Add your implementation code here.
}

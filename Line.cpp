#include "Line.h"

Line::Line()
{
	char name[] = "Line";
	type = new char[strlen(name) + 1];
	strcpy_s(type, strlen(name) + 1, name);
}

Line::Line(double x1, double y1, double x2, double y2, int c)
		: OpenShape(x1, y1, c)
{
	char name[] = "Line";
	type = new char[strlen(name) + 1];
	strcpy_s(type, strlen(name) + 1, name);
	addPoint(x2, y2);
}

Line::~Line()
{
}

void Line::draw()
{
	GP142_lineXY(color, points[0].x, points[0].y, points[1].x, points[1].y, 2);
	//GP142_printfXY
	//GP142_logging();
	// TODO: Add your implementation code here.
}

bool Line::contains(Point p)
{
	/*if (points[1].x == points[0].x && p.x == points[1].x && p.y<points[])
		return true;*/
	if (points[1].y == points[0].y && p.y == points[1].y)
		return true;
	if ((((p.x - points[0].x) * (points[1].y - points[0].y)) /
			 ((p.y - points[0].y) * (points[1].x - points[0].x))) == 1)
		return true;
	else
		return false;
}

//void Line::changeColor()
//{
//	// TODO: Add your implementation code here.
//}

void Line::changeColor(int color)
{
	Shape::color = color;
	// TODO: Add your implementation code here.
}

void Line::erase()
{
	// TODO: Add your implementation code here.
}

void Line::fill(int, int, int c, COLORREF)
{
	changeColor(c);
	Line::draw();
}

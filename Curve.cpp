#include "Curve.h"

Curve::Curve()
{
	char name[] = "Curve";
	type = new char[strlen(name) + 1];
	strcpy_s(type, strlen(name) + 1, name);
}

Curve::Curve(int x, int y, int c)
		: OpenShape(x, y, c)
{
	char name[] = "Curve";
	type = new char[strlen(name) + 1];
	strcpy_s(type, strlen(name) + 1, name);
}

Curve::~Curve()
{
}

void Curve::draw()
{
	for (int i = 0; i < points.size() - 1; i++)
		GP142_lineXY(color, points[i].x, points[i].y, points[i + 1].x, points[i + 1].y, 2);
	// TODO: Add your implementation code here.
}

bool Curve::contains(Point p)
{
	// TODO: Add your implementation code here.
	return false;
}

void Curve::changeColor(int color)
{
	color = color;
	// TODO: Add your implementation code here.
}

bool Curve::check_end()
{
	if (points.size() >= 2)
	{
		if (points[points.size() - 1].x == points[points.size() - 2].x && points[points.size() - 1].y == points[points.size() - 2].y)
			return true;
	}
	return false;
}

void Curve::fill(int, int, int c, COLORREF)
{
	changeColor(c);
	Curve::draw();
}

void Curve::erase()
{
	// TODO: Add your implementation code here.
}

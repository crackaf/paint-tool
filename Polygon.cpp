#include "Polygon.h"

My_Polygon::My_Polygon()
{
	fillColor = -1;
	char name[] = "Polygon";
	type = new char[strlen(name) + 1];
	strcpy_s(type, strlen(name) + 1, name);
}

My_Polygon::My_Polygon(double x, double y, int c)
		: Shape(x, y, c), fillColor(-1)
{
	char name[] = "Polygon";
	type = new char[strlen(name) + 1];
	strcpy_s(type, strlen(name) + 1, name);
}

My_Polygon::~My_Polygon()
{
}

void My_Polygon::draw()
{
	for (int i = 0; i < points.size() - 1; i++)
		GP142_lineXY(color, points[i].x, points[i].y, points[i + 1].x, points[i + 1].y, 2);
	// TODO: Add your implementation code here.
}

//void Polygon::fill()
//{
//	// TODO: Add your implementation code here.
//}

bool My_Polygon::contains(Point p)
{
	// TODO: Add your implementation code here.
	return false;
}

//void My_Polygon::fill(int color)
//{
//	// TODO: Add your implementation code here.
//}

bool My_Polygon::check_end()
{
	if (points.size() >= 2)
	{
		if (points[points.size() - 1].x == points[points.size() - 2].x && points[points.size() - 1].y == points[points.size() - 2].y)
		{
			GP142_lineXY(color, points[0].x, points[0].y, points[points.size() - 1].x, points[points.size() - 1].y, 2);
			points.pop_back();
			return true;
		}
	}
	return false;
}

void My_Polygon::addPoint(double x, double y)
{
	Shape::addPoint(x, y);
}

//void My_Polygon::erase()
//{
//	// TODO: Add your implementation code here.
//}

void My_Polygon::erase()
{

	// TODO: Add your implementation code here.
}

void My_Polygon::fill(int x, int y, int c, COLORREF bck)
{
	fillColor = c;
	Shape::fill(x, y, c, bck);
}

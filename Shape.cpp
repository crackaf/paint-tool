#include "Shape.h"

Shape::Shape()
{
  color = 0;
  numberOfPoints = 0;
  char name[] = "Shape";
  type = new char[strlen(name) + 1];
  strcpy_s(type, strlen(name) + 1, name);
  //points = nullptr;
}

Shape::Shape(double x, double y, int c)
{
  color = c;
  /*points = new Point[1];
	points[0].x = x;
	points[0].y = y;*/
  Point p;
  p.x = x;
  p.y = y;
  points.push_back(p);
  numberOfPoints = 1;
  char name[] = "Shape";
  type = new char[strlen(name) + 1];
  strcpy_s(type, strlen(name) + 1, name);
}

Shape::~Shape()
{
}

void Shape::addPoint(double x, double y)
{
  Point p;
  p.x = x;
  p.y = y;
  points.push_back(p);
  // TODO: Add your implementation code here.
}

bool Shape::contains(Point p)
{
  // TODO: Add your implementation code here.
  return false;
}

//void Shape::fill(int x, int y, int color)
//{
//}

void Shape::fill(int x, int y, int color, COLORREF bck_color)
{
  if (get_Pixel(x, y) == bck_color)
  {
    set_Pixel(x, y, get_color_colorref(color));
    Shape::fill(x + 1, y, color, bck_color);
    Shape::fill(x - 1, y, color, bck_color);
    Shape::fill(x, y + 1, color, bck_color);
    Shape::fill(x, y - 1, color, bck_color);
  }
}

char *Shape::getname()
{
  return type;
}

//void Shape::serialize()
//{
//}

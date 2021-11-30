#include "Circle.h"

Circle::Circle(void)
{
  fillColor = -1;
  radius = 0.0;
  char name[] = "Circle";
  type = new char[strlen(name) + 1];
  strcpy_s(type, strlen(name) + 1, name);
}

Circle::Circle(double x1, double y1, double x2, double y2, int _color)
    : Shape(x1, y1, _color)
{
  //points = new Point[1];
  fillColor = -1;
  radius = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
  char name[] = "Circle";
  type = new char[strlen(name) + 1];
  strcpy_s(type, strlen(name) + 1, name);

  /*points[0].x = x1;
	points[0].y = y1;*/
  /*p->x = x2;
	p->y = y2;*/
}

Circle::~Circle()
{
}

//bool Circle::contains(Point p)
//{
//	// TODO: Add your implementation code here.
//	return false;
//}

void Circle::draw()
{
  GP142_circleXY(color, points[0].x, points[0].y, radius, 2);
  // TODO: Add your implementation code here.
}

void Circle::fill(int x, int y, int c, COLORREF bck)
{
  Shape::fill(x, y, c, bck);
  fillColor = c;
}

//void Circle::fill()
//{
//	// TODO: Add your implementation code here.
//}

bool Circle::contains(Point p)
{
  double d = sqrt(pow(p.x - points[0].x, 2) + pow(p.y - points[0].y, 2));
  // TODO: Add your implementation code here.
  return (d <= radius);
}

void Circle::erase()
{
  GP142_circleXY(BLACK, points[0].x, points[0].y, radius, 0);
}

void Circle::serialization()
{
  ofstream file("array_save.txt", ios::binary);
  if (file.is_open())
  {
    file << type << "," << sizeof(this) << ",";
    file.write((char *)this, sizeof(this));
    file << ";";
  }
}

//void Circle::fill(int x, int y, int color, int bck_color)
//{
//	if (get_Pixel(x, y) == get_color_colorref(bck_color))
//	{
//		set_Pixel(x, y, get_color_colorref(color));
//		Circle::fill(x + 1, y, color, bck_color);
//		Circle::fill(x - 1, y, color, bck_color);
//		Circle::fill(x, y + 1, color, bck_color);
//		Circle::fill(x, y - 1, color, bck_color);
//	}
//	//if()
//	// TODO: Add your implementation code here.
//}

#pragma once
#include "GP142.H"
#include "GP142LIB.H"
#include <vector>
#include <string>
#include <fstream>
//#include <array>
using namespace std;
//#include <vector>

struct Point
{
  int x, y;
};

class Shape
{
public:
  Shape();
  Shape(double, double, int = 1);
  virtual ~Shape();
  void addPoint(double, double);
  virtual void erase() = 0;
  virtual void draw() = 0;
  virtual bool contains(Point p);
  //void fill(int, int, int);
  virtual void fill(int, int, int, COLORREF);
  char *getname();
  //void serialize();
protected:
  int color;
  int numberOfPoints;
  vector<Point> points;
  char *type;
};

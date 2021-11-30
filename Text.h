#pragma once
#include "Shape.h"
#define TEXT_SIZE 20

class Text : public Shape
{
private:
  //	char* type;
  string text;
  int pointer;

public:
  Text();
  Text(string &temp, double x = 0, double y = 0, int c = 1, int p = 0);
  Text(int, int, int = 1);
  Text(char temp, double x = 0, double y = 0, int c = 1, int p = 0);
  void fill(int, int, int, COLORREF);
  //Text(char )
  ~Text();
  void draw();
  void addChar(char c);
  void changeColor(int c);
  bool contains(Point p);
  void erase();
};

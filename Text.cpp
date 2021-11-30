#include "Text.h"

Text::Text()
{
  char name[] = "Text";
  type = new char[strlen(name) + 1];
  strcpy_s(type, strlen(name) + 1, name);
}

Text::Text(string &temp, double x, double y, int c, int p)
    : Shape(x, y, c), pointer(p)
{
  char name[] = "Text";
  type = new char[strlen(name) + 1];
  strcpy_s(type, strlen(name) + 1, name);
  //addPoint(x, y);
  text += temp;
  //pointer = temp.size();
}

Text::Text(int x, int y, int c)
    : Shape(x, y, c), pointer(0)
{
  char name[] = "Text";
  type = new char[strlen(name) + 1];
  strcpy_s(type, strlen(name) + 1, name);
}

Text::Text(char temp, double x, double y, int c, int p)
    : Shape(x, y, c), pointer(p)
{
  char name[] = "Text";
  type = new char[strlen(name) + 1];
  strcpy_s(type, strlen(name) + 1, name);
  //addPoint(x, y);
  addChar(temp);
}

void Text::fill(int, int, int c, COLORREF)
{
  color = c;
  Text::draw();
}

Text::~Text()
{
}

void Text::draw()
{
  //for (int i = pointer, x = points[0].x , y = points[0].y; i < text.size(); i++/*, x += 10, pointer++*/)
  //{
  //	//char c = text[line][i];
  //	if (x > 460)
  //	{

  //		/*points[line + 1].x = x;
  //		points[line + 1].y = y;
  //		Point p;
  //		p.x = -490;
  //		p.y = y - 20;
  //		points.push_back(p);
  //		text.push_back("");
  //		text[line + 1] += c;
  //		pointer = 0;
  //		line++;*/

  //		text += '\n';
  //	}
  //	//char c = text[line][i];
  //	GP142_printfXY(color, x, y, TEXT_SIZE, text.c_str());
  //	/*points[line + 1].x = x;
  //	points[line + 1].y = y;*/
  //}
  //char* str;
  //strcpy(str, text.c_str());

  GP142_printfXY(color, points[0].x, points[0].y, TEXT_SIZE, text.c_str());

  if (points[0].x + 10 * pointer > 460)
  {
    addChar('\n');
    pointer = 0;
  }

  // TODO: Add your implementation code here.
}

void Text::addChar(char c)
{
  if (c != '\0')
  {
    if (text[0] == '\0')
      text = +c;
    else
      text += c;

    pointer++;
  }
}

void Text::changeColor(int c = 1)
{
  color = c;
}

bool Text::contains(Point p)
{
  int count = 0;
  bool flag = false;
  for (int i = 0; i < text.size(); i++)
    if (text[i] == '\n')
      count++;
  if (count != 0)
  {
    Point temp;
    temp.x = 460;
    temp.y = points[0].y - 20 * count;
    points[0].y += 20;
    points.push_back(temp);

    if (((points[0].x < p.y && p.y < points[1].y) || (points[1].y < p.y && p.y < points[0].y)) &&
        ((points[0].x < p.x && p.x < points[1].x) || (points[1].x < p.x && p.x < points[0].x)))
      flag = true;
    else
      flag = false;
  }
  else
  {
    Point temp;
    temp.x = points[0].x + 10 * pointer;
    temp.y = points[0].y;
    points[0].y += 20;
    points.push_back(temp);

    if (((points[0].x < p.y && p.y < points[1].y) || (points[1].y < p.y && p.y < points[0].y)) &&
        ((points[0].x < p.x && p.x < points[1].x) || (points[1].x < p.x && p.x < points[0].x)))
      flag = true;
    else
      flag = false;
  }
  //points.pop_back();
  points[0].y -= 20;

  return flag;
}
////////next line///////

void Text::erase()
{
  GP142_rectangleXY(BLACK, points[0].x, points[0].y + 20, points[1].x, points[1].y, 0);
  // TODO: Add your implementation code here.
}

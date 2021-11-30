#include "OpenShape.h"

OpenShape::OpenShape()
{
	style = false;
	char name[] = "OpenShape";
	type = new char[strlen(name) + 1];
	strcpy_s(type, strlen(name) + 1, name);
	//  fillColor = 0;
}

OpenShape::OpenShape(int x, int y, int c)
		: Shape(x, y, c)
{
	style = false;
	char name[] = "OpenShape";
	type = new char[strlen(name) + 1];
	strcpy_s(type, strlen(name) + 1, name);
}

OpenShape::~OpenShape()
{
}

void OpenShape::erase()
{
	// TODO: Add your implementation code here.
}

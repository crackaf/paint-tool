#pragma once
#include "Paint.h"

Paint::Paint()
{
	color = 1;
}

void Paint::openMenu()
{

	//fptr = new void[14];
	GP142_open();

	GP142_rectangleXY(WHITE, -490, 330, 490, -275, 3);
	My_Rectangle temp(-370, 330, 490, -275);

	Menu.push_back(new My_Rectangle(-370, 330, 490, -275)); //border

	for (int i = 0, y1 = 320, y2 = 280; i < 4; i++, y1 -= 50, y2 -= 50) //index 1-9
	{
		Menu.push_back(new My_Rectangle(-480, y1, -440, y2));
		Menu.push_back(new My_Rectangle(-435, y1, -395, y2));
	}

	for (int i = 0, c = 0, y1 = 20, y2 = 50; i < 8; i++, c++, y1 -= 40, y2 -= 40) //10-size;
	{
		Menu.push_back(new My_Rectangle(-480, y1, -450, y2));
		Menu.push_back(new My_Rectangle(-445, y1, -415, y2));
		if (i < 7)
			Menu.push_back(new My_Rectangle(-410, y1, -380, y2));
	}
	//int y1 = 20, c = 1;
	////fill(-470, y1+10, c, get_Pixel(-470, y1+10 ));
	//c++;

	//Menu.push_back(new My_Rectangle(-410,,-380))

	for (int i = 0; i < Menu.size(); i++)
		Menu[i]->draw();
	/*y1 -= 40*7;
	fill(-470, y1 + 10, c, get_Pixel(-470, y1 + 10));
	fill(-435, y1 + 10, c, get_Pixel(-435, y1 + 10));
	fill(-400, y1 + 10, c, get_Pixel(-400, y1 + 10));*/

	for (int c = 1, y = 20; c < 23; c++, y -= 40)
	{
		fill(-470, y + 10, c, get_Pixel(-470, y + 10));
		c++;
		fill(-435, y + 10, c, get_Pixel(-435, y + 10));
		c++;
		if (c < 24)
			fill(-400, y + 10, c, get_Pixel(-400, y + 10));
	}

	//MAX_COLORS
	/*for (int i = WHITE, y = 310; i < 23; i++, y = y - 50)
	{
		fill(-465, y, i, get_Pixel(-470, y));
		i++;
		fill(-425, y, i, get_Pixel(-430, y));
	}*/
	//int y = 315;
	//fill(-470, y, GREEN, get_Pixel(-470, y));
	////i++;
	//fill(-430, y, BLUE, get_Pixel(-430, y));
	//y = y - 50;
	//fill(-470, y, GREEN, get_Pixel(-470, y));
	////i++;
	//fill(-430, y, BLUE, get_Pixel(-430, y));

	//Menu.push_back(new My_Rectangle(-480, 320, -440, 280));//line
	//Menu.push_back(new My_Rectangle(-435, 320, -395, 280));

	//Menu.push_back(new My_Rectangle(-480, 275, -440, 235));// rectangle
	//Menu.push_back(new My_Rectangle(-435, 275, -395, 235));

	//Menu.push_back(new My_Rectangle(-480, 230, -440, 190));//curve
	//Menu.push_back(new My_Rectangle(-435, 230, -395, 190));

	//Menu.push_back(new My_Rectangle(-480, 185, -440, 145));//polygon
	//Menu.push_back(new My_Rectangle(-435, 185, -395, 145));

	//Menu.push_back(new My_Rectangle(-480, 140, -440, 100));// circle
	//Menu.push_back(new My_Rectangle(-435, 140, -395, 100));

	//text
	//save
	//load
	//colors

	//////////////////////////////////////////////////////////
	//GP142_lineXY(WHITE, -370, 330, -370, -275, 2);//verticle line
	GP142_lineXY(WHITE, -470, 310, -450, 290, 1);

	GP142_rectangleXY(WHITE, -425, 310, -405, 290, 2);
	GP142_lineXY(WHITE, -474, 240, -472, 265, 1);
	GP142_lineXY(WHITE, -472, 265, -449, 259, 1);
	GP142_lineXY(WHITE, -449, 259, -460, 232, 1);
	GP142_lineXY(WHITE, -460, 231, -474, 240, 1);
	GP142_circleXY(WHITE, -416, 250, 10, 2);
	GP142_lineXY(WHITE, -476, 188, -461, 212, 1);
	GP142_lineXY(WHITE, -461, 212, -449, 183, 1);
	GP142_printfXY(WHITE, -423, 182, 30, "T");
	GP142_printfXY(WHITE, -476, 140, 17, "FILL");

	//-420 185
}

void Paint::OnStart()
{
	openMenu();

	int quit = 0, mx, my;
	char key;

	while (!quit)
	{
		switch (GP142_await_event(&mx, &my, &key))
		{
		case GP142_QUIT:
			quit = 1;
			break;

		case GP142_MOUSE:
			check_points(mx, my);
			break;

		default:
			break;
		}
	}
}

bool Paint::check_points(int x, int y)
{
	if (x < -370)
	{
		Point p;
		p.x = x;
		p.y = y;

		for (int i = 1; i < 11; i++)
		{
			if (Menu[i]->contains(p))
			{
				functions(i);
				return false;
			}
		}

		for (int i = 11; i < Menu.size(); i++)
		{
			if (Menu[i]->contains(p))
			{
				color = i - 10;
				return false;
			}
		}

		return false;
	}
	return true;
}

void Paint::functions(int i)
{
	if (i == linem)
	{
		line();
	}
	else if (i == rectanglem)
	{
		rectangle();
	}
	else if (i == curvem)
	{
		curve();
	}
	else if (i == circlem)
	{
		circle();
	}
	else if (i == polygonm)
	{
		polygon();
	}
	else if (i == textm)
	{
		text();
	}
	else if (i == fillm)
	{
		fill();
	}
}

void Paint::line()
{
	int mx, my;
	char key;
	GP142_await_event(&mx, &my, &key);
	if (check_points(mx, my))
	{
		int x, y;
		GP142_await_event(&x, &y, &key);
		if (check_points(x, y))
		{
			allShapes.push_back(new Line(mx, my, x, y, color));
			allShapes[allShapes.size() - 1]->draw();
		}
	}
}

void Paint::rectangle()
{
	int mx, my;
	char key;
	GP142_await_event(&mx, &my, &key);
	if (check_points(mx, my))
	{
		int x, y;
		GP142_await_event(&x, &y, &key);
		if (check_points(x, y))
		{
			allShapes.push_back(new My_Rectangle(mx, my, x, y, color));
			allShapes[allShapes.size() - 1]->draw();
		}
	}
}

void Paint::polygon()
{
	int mx, my;
	char key;
	GP142_await_event(&mx, &my, &key);
	if (check_points(mx, my))
	{
		My_Polygon *temp = new My_Polygon(mx, my, color);
		while (!temp->check_end() && GP142_await_event(&mx, &my, &key) /*&& !temp->check_end()*/)
		{
			if (check_points(mx, my))
			{
				temp->addPoint(mx, my);
				temp->draw();
			}
			else
			{
				allShapes.push_back(temp);
				return;
			}
		}
		allShapes.push_back(temp);
	}
}

void Paint::circle()
{
	int mx, my;
	char key;
	GP142_await_event(&mx, &my, &key);
	if (check_points(mx, my))
	{
		int x, y;
		GP142_await_event(&x, &y, &key);
		if (check_points(x, y))
		{
			allShapes.push_back(new Circle(mx, my, x, y, color));
			allShapes[allShapes.size() - 1]->draw();
		}
	}
}

void Paint::curve()
{
	int mx, my;
	char key;
	GP142_await_event(&mx, &my, &key);
	if (check_points(mx, my))
	{
		Curve *temp = new Curve(mx, my, color);
		while (!temp->check_end() && GP142_await_event(&mx, &my, &key) /*&& !temp->check_end()*/)
		{
			if (check_points(mx, my))
			{
				temp->addPoint(mx, my);
				temp->draw();
			}
			else
			{
				allShapes.push_back(temp);
				return;
			}
		}
		allShapes.push_back(temp);
	}
}

void Paint::text()
{
	int mx, my;
	char key;
	GP142_await_event(&mx, &my, &key);
	if (check_points(mx, my))
	{
		Text *temp = new Text(mx, my, color);
		while (GP142_await_event(&mx, &my, &key))
		{
			if (check_points(mx, my))
			{
				temp->addChar(key);
				temp->draw();
			}
			else
			{
				allShapes.push_back(temp);
				return;
			}
		}
		allShapes.push_back(temp);
	}
}

void Paint::fill()
{
	int mx, my;
	char key;
	GP142_await_event(&mx, &my, &key);
	if (check_points(mx, my))
	{
		fill(mx, my, color, get_Pixel(mx, my));

		GP142_lineXY(WHITE, -474, 240, -472, 265, 1);
	}
}

void Paint::fill(int x, int y, int color, COLORREF bck_color)
{
	if (get_Pixel(x, y) == bck_color)
	{
		set_Pixel(x, y, get_color_colorref(color));
		Paint::fill(x + 1, y, color, bck_color);
		Paint::fill(x - 1, y, color, bck_color);
		Paint::fill(x, y + 1, color, bck_color);
		Paint::fill(x, y - 1, color, bck_color);
	}
}

Paint::~Paint()
{
}

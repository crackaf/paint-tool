
/*
 * CSE/ENGR 142 GP142_Demo
 *
 * 1/25/95
 * Author(s):         Larry Ruzzo
 * Email Address(s):  ruzzo@cs.washington.edu
 *
 * This program is a demo of some of the features of
 * GP142 --- the CSE/ENGR 142 Graphics Package.
 * It includes simple drawing commands, keyboard and mouse
 * interaction, and a simple animation.
 *
 * Revision history:
 * 11/18/97 Dan Boren  - Removed calls to obsolete function GP142_undo()
 *
 */

#include "GP142.h"
#include "Paint.h"
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Polygon.h"
#include "Text.h"
#include "OpenShape.h"
#include "Curve.h"
//#include "iostream"
#include <stdio.h>
#include <math.h>
#define PI 3.1415926535
#define ANIMATE_MSG "Select \"Animate\"\nOn the \"Run\" Menu"

//using namespace std;

//#include <vector>

//You will use the following 5 functions do to all work

//A) DRAWING FUNCTIONS
//the two drawing functions that you will use to make all shapes
void draw_line(int x1, int y1, int x2, int y2, int color = WHITE, int width = 2)
{
	GP142_lineXY(color, x1, y1, x2, y2, width);
}

void draw_circle(int x, int y, int radius, int color = GREEN)
{
	GP142_circleXY(color, x, y, radius, 2);
}

//B) EVENT HANDLERS
//Mouse handler
void handle_mouse(int x, int y)
{
	GP142_printfXY(YELLOW, x, y, 9, "(%d,%d)", x, y);
}

//Keyboard handler
//void handle_kbd(char c, int x, int y)
//{
//	//put the character anywhere you want to.
//	//I'm putting it on the origin
//	GP142_printfXY(WHITE, x, y, TEXT_SIZE, "%c", c);
//}

//periodic handler you will not need to use because we're not doing animation
//void demo_handle_periodic(void) {};

/******************************************************************************
 *
 * The Main Program
 * ----------------
 *
 * The main program takes care of initialization and cleanup, and the high-level
 * control of all actions in the program, but most of the detail work is
 * relegated to sub-functions, so that the structure of main stays clear and
 * simple.
 *
 */
int main(void)
{
	//std::vector<int> abc(5);
	int quit = 0; /* has user signaled quit yet?                      */
	int mouse_x, mouse_y, mouse_a, mouse_b, mouse_d, mouse_c;
	char key_pressed;
	//GP142_open();           /* Open and initialize the GP142 Graphics Window    */

	int pcount = 0;
	int points[4];
	double r = 0;
	Paint k;
	k.OnStart();

	/*GP142_printfXY(WHITE, 0, 0, 20, "fuck");
	GP142_printfXY(BLACK, 0, 0, 20, "fuck");
	GP142_textXY(WHITE, 0, 30, 20, "fuck");
	GP142_textXY(BLACK, 0, 30, 20, "fuck");*/
	/*GP142_await_event(&mouse_x, &mouse_y, &key_pressed);

	GP142_await_event(&mouse_a, &mouse_b, &key_pressed);

	Circle temp(mouse_x, mouse_y, mouse_a, mouse_b);
	temp.serialization();*/

	//	k.save_shapes();
	//k.load_canvas();
	//k.save_canvas();
	//	GP142_await_event(&mouse_a, &mouse_b, &key_pressed);
	//	GP142_await_event(&mouse_x, &mouse_y, &key_pressed);
	//	//Text temp(key_pressed, mouse_x, mouse_y);
	//	//Curve temp(mouse_x, mouse_y);
	////	Paint k;
	//	//temp.draw();
	//	//printf()
	//	//The Event Loop
	//	My_Rectangle temp(mouse_x, mouse_y, mouse_a, mouse_b);
	//while (GP142_await_event(&mouse_x, &mouse_y, &key_pressed))
	//{

	//
	//	GP142_await_event(&mouse_a, &mouse_b, &key_pressed);
	//	//switch (GP142_await_event(&mouse_x, &mouse_y, &key_pressed)) {
	//	//case GP142_QUIT:
	//	//	quit = 1;   /* set flag to terminate loop                */
	//	//	break;

	//	//case GP142_MOUSE:
	//	//
	//	My_Rectangle temp(mouse_x, mouse_y, mouse_a, mouse_b);
	//	temp.draw();
	//	while (GP142_await_event(&mouse_a, &mouse_b, &key_pressed))
	//	{
	//		Point p;
	//		p.x = mouse_a;
	//		p.y = mouse_b;
	//		if (temp.contains(p))
	//			system("pause");
	//	}

	//handle_mouse(mouse_x,mouse_y);
	/*Circle temp(mouse_x, mouse_y, mouse_a, mouse_b);
		temp.draw();
		GP142_await_event(&mouse_a, &mouse_b, &key_pressed);
		
		temp.fill(mouse_a, mouse_b, GREEN, get_color_colorref(get_Pixel(mouse_a, mouse_b)));
		*/
	//
	//			/*	points[2*pcount]=mouse_x;
	//				points[2*pcount+1]=mouse_y;
	//				pcount++;

	//				if(pcount==2)
	//				{
	//					pcount=0;
	//					draw_line(points[0],points[1],
	//						  points[2],points[3]);
	//				}*/

	//	//GP142_await_event(&mouse_a, &mouse_b, &key_pressed);
	//	//
	//	//r = sqrt(pow(mouse_x - mouse_a, 2) + pow(mouse_y - mouse_b, 2));

	//	//GP142_circleXY(GREEN, mouse_x, mouse_y, r);
	//	/*Circle temp(mouse_x, mouse_y, mouse_a, mouse_b, GREEN);
	//	temp.draw();

	//GP142_await_event(&mouse_c, &mouse_d, &key_pressed);
	/*temp.addChar(key_pressed);
			temp.draw();
			if (pcount % 5 == 0)
			{
				GP142_await_event(&mouse_c, &mouse_d, &key_pressed);
				Point p;
				p.x = mouse_c;
				p.y = mouse_d;
				if (temp.contains(p))
					system("pause");
			}
			pcount++;*/
	//GP142_printfXY(1, 345, 0, TEXT_SIZE, "sdfasfasf\nasfasfasdfasdfasdfasdfasdfasf");
	//	Point p;
	//	p.x = mouse_c;
	//	p.y = mouse_d;

	//	if (temp.contains(p))
	//		system("pause");*/

	//	My_Rectangle temp(mouse_x, mouse_y, mouse_a, mouse_b, GREEN);
	//	temp.draw();
	/*temp.addPoint(mouse_x, mouse_y);
		temp.draw();
		if (temp.check_end())
			system("pause");*/

	/*char temp[] = "asdfasdfaghvjhgjhgkjgjkgkgkjgjkgkjgjk";

		GP142_printfXY(1, 345, 0, 20, temp);
		*/

	//

	//	//cout<<temp.contains(p);
	//	//system("pause");

	//	break;

	/*case GP142_KBD:
		{*/
	/*GP142_printfXY(YELLOW, mouse_x, mouse_y, 9, "Mouse at (%d,%d)", mouse_x, mouse_y);
		temp.addChar( key_pressed);
		temp.draw();
		temp.changeColor(++quit);*/

	/*GP142_printfXY(BLACK, 0, 0, TEXT_SIZE, "%c", c);
		GP142_printfXY(BLACK, 0, 0, TEXT_SIZE, "%c", c);
		GP142_printfXY(BLACK, 0, 0, TEXT_SIZE, "%c", c);
		GP142_printfXY(BLACK, 0, 0, TEXT_SIZE, "%c", c);
		GP142_printfXY(BLACK, 0, 0, TEXT_SIZE, "%c", c);
		GP142_printfXY(BLACK, 0, 0, TEXT_SIZE, "%c", c);
		GP142_printfXY(BLACK, 0, 0, TEXT_SIZE, "%c", c);*/
	//GP142_clear();

	//k.save_canvas();

	GP142_close(); /* Clean up and close graphics window           */

	return 0;
}

/*
				points[2*pcount]=mouse_x;
				points[2*pcount+1]=mouse_y;
				pcount++;

				if(pcount==2)
				{
					pcount=0;
					draw_line(points[0],points[1],
							  points[2],points[3]);
				}*/

//draw_circle(mouse_x,mouse_y,10);

#ifndef _POINT_H_
#define _POINT_H_

#include <iostream>
#include "io_utils.h"


using namespace std;

class Point {
	enum { ROWS = 20, COLS = 80 };
	int x, y;
public:
	Point(int _x=1, int _y=1) { x = _x, y = _y; }
	bool operator== (Point p) { return (this->x == p.x) && this->y == p.y; }

	int getX() const{
		return x;
	}
	int getY() const{
		return y;
	}
	void set(int a, int b){
		x = a;
		y = b;
	}
	void draw(char ch)
	{
		gotoxy(x, y);
		cout << ch;
		cout.flush();
	}
	void move();
	void move(int direction);
	Point next(int direction)
	{
		Point next = *this;
		next.move(direction);
		return next;
	}
};
#endif
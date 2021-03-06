#ifndef _BULLET_H_
#define _BULLET_H_

#include "Point.h"
#include "Color.h"

class Bullet :public Point {
	int direction;
	Color color;
	char symbol = '*';
	bool active=false;

public:
	void setActiveStatus(bool val) {
		active = val;
	}
	void init(Color _color, int _direction) {
		color = _color;
		direction = _direction;
	}
	bool isActive() {
		return active;
	}
	int getDirection() {
		return direction;
	}
	Point getPos() {
		Point pos;
		pos.set(Point::getX(),Point::getY());
		return pos;
	}
};

#endif
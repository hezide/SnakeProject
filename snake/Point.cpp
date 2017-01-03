#include "Point.h"

void Point::move() {
	int dir = rand() % 4;
	move(dir);
}

void Point::move(int dir) {
	switch (dir) {
	case 0: // UP
		--y;
		if (y < 1) {
			y = ROWS-2;
		}
		break;
	case 1: // RIGHT
		++x;
		if (x > COLS-2) {
			x = 1;
		}
		break;
	case 2: // DOWN
		++y;
		if (y > ROWS-2) {
			y = 1;
		}
		break;
	case 3: // LEFT
		--x;
		if (x < 1) {
			x = COLS-2;
		}
		break;
	}
}
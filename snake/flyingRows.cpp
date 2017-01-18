#include "flyingRows.h"
#include "TheSnakesGame.h"

void flyingRows::move()
{
	int x = getX();
	int y = getY();
	int direction = getDirection();

	switch (direction) {
	case 1: // RIGHT
		++x;
		if (x > COLS - 2) {
			if(getCrossingWalls())
				x = 1;
			else {
				setDirection(3);
				x--;
			}
		}
		break;
	case 3: // LEFT
		--x;
		if (x < 1) {
			if (getCrossingWalls())
				x = COLS - 2;
			else {
				setDirection(1);
				x++;
			}
		}
		break;
	}
	set(x, y);
}

void flyingRows::init()
{
	if (getCrossingWalls())
	{
		set(30, 18);
		setDirection(1);
	}
	else {
		set(50,11);
		setDirection(3);
	}
	setBulletProof(true);
	setSymbol('!');
	setIsActive(true);
}

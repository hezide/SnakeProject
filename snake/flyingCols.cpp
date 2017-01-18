#include "flyingCols.h"
#include "TheSnakesGame.h"

void flyingCols::move()
{
	int x = getX();
	int y = getY();
	int direction = getDirection();

	switch (direction) {
	case 0: // UP
		--y;
		if (y <1) {
			if (getCrossingWalls())
				y = ROWS - 2;
			else {
				setDirection(2);
				y++;
			}
		}
		break;
	case 2: //DOWN
		++y;
		if (y > ROWS-2) {
			if (getCrossingWalls())
				y = 1;
			else {
				setDirection(0);
				y--;
			}
		}
		break;
	}
	set(x, y);
}

void flyingCols::init()
{
	if (getCrossingWalls())
	{
		set(55, 18);
		setDirection(2);
	}
	else {
		set(45, 11);
		setDirection(0);
	}
	setBulletProof(false);
	setSymbol('$');
	setIsActive(true);
}



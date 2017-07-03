#include "numberEater.h"
#include "TheSnakesGame.h"

void numberEater::init()
{
	set(10, 17);
	setColor(Color::LIGHTMAGENTA);
	setDirection(DONT_MOVE);
	setDoubleSpeed(true);
	setBulletProof(false);
	setSymbol('%');
	setIsActive(true);
}
void numberEater::setDirectionToNumber()
{
	Point posToGo,pos;
	if (!getGame()->checkIfThereAreMatchingNumbers())//if there is no correct answer. stand
		setDirection(DONT_MOVE);
	else {
		pos.set(getX(), getY());
		posToGo = getGame()->findTheClosestNumber(pos);//find the closest number to numberEater in the board
		fixXYAxis(posToGo);
	}
}
void numberEater::fixXYAxis(Point posToGo)
{
	if (getX() != posToGo.getX())
	{
		if (abs(getX() - posToGo.getX()) > 39)
			if (getX() > posToGo.getX())
				setDirection(1);
			else
				setDirection(3);
		else
			if (getX() > posToGo.getX())
				setDirection(3);
			else
				setDirection(1);
	}
	else if (getY() != posToGo.getY())
	{
		if (abs(getY() - posToGo.getY()) > 9)
			if (getY() > posToGo.getY())
				setDirection(2);
			else
				setDirection(0);
		else
			if (getY() > posToGo.getY())
				setDirection(0);
			else
				setDirection(2);
	}
}
void numberEater::move()
{
	setDirectionToNumber();
	nextStepIsPossible();				  
	int dir = getDirection();
	int x = getX();
	int y = getY();
	switch (dir) {
	case 0: // UP
		--y;
		if (y < 1) {
			y = ROWS - 2;
		}
		break;
	case 1: // RIGHT
		++x;
		if (x > COLS - 2) {
			x = 1;
		}
		break;
	case 2: // DOWN
		++y;
		if (y > ROWS - 2) {
			y = 1;
		}
		break;
	case 3: // LEFT
		--x;
		if (x < 1) {
			x = COLS - 2;
		}
		break;
	}
	set(x, y);
}
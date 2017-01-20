#include "Creature.h"
#include "TheSnakesGame.h"

void Creature::moveAndDraw()
{
		Point pos;
		if (getIsActive()) {//runs only if the creature is active
			pos.set(getX(), getY());
			move();
			getGame()->getBoard(1).insertCharToBoard(' ', pos);
			pos.draw(' ');
			pos.set(getX(), getY());
			getGame()->getBoard(1).insertCharToBoard(getSymbol(), pos,color);
			draw(getSymbol(),color);
		}

}

void Creature::nextStepIsPossible()
{
	char ch;

	Point pos(getX(), getY());
	TheSnakesGame* theGame = getGame();
	pos = pos.next(getDirection());
	ch = theGame->getBoard(1).getChFromBoard(pos.getX(), pos.getY());

	switch (ch) {
	case '@':
		theGame->disappearSpecificSnake(0);
		break;
	case '#':
		theGame->disappearSpecificSnake(1);
		break;
	case '*'://creature hits a bullet
		theGame->findBulletInBothSnakes(pos)->setActiveStatus(false);
		theGame->getBoard(1).insertCharToBoard(' ', pos);
		pos.draw(' ');
		if (!getIsBulletProof())
			disappearCreature();
		break;
	}

	if (ch >= '0' && ch <= '9') {
		Number& eatenNum = theGame->getBoard(1).getNumber(pos);
		theGame->getBoard(1).removeNumber(eatenNum);
	}

}

void Creature::disappearCreature()
{
	Point pos;
	pos.set(getX(), getY());
	theGame->getBoard(1).insertCharToBoard(' ', pos);
	draw(' ');
	setIsActive(false);
}

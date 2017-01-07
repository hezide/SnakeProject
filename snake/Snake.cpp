#include "Snake.h"
#include "TheSnakesGame.h"

void Snake::setPosition(int y, int x)
{
	for (int i = 0; i < initSize; i++)
		body[i].set(x, y);
}

void Snake::move() {
	Point p;

	if (nextStepIsPossible()!=2)//check if one of the snakes hit himself or in the other snake
	{
		p.set(body[size - 1].getX(), body[size - 1].getY());
		body[size - 1].draw(' ');
		theGame->getBoard(1).insertCharToBoard(' ', p);
		for (int i = size - 1; i > 0; --i) {
			body[i] = body[i - 1];
		}
		body[0].move(direction);
		setTextColor(color);
		body[0].draw(symbol);
		p.set(body[0].getX(), body[0].getY());

		theGame->getBoard(1).insertCharToBoard(symbol, p);
		setTextColor(Color::WHITE);

	}
}

int Snake::getDirection(char key) {
	for (int i = 0; i < 5; ++i) {
		if (key == arrowKeys[i]) {
			if (i == 4)
				shoot();
			else
				return i;
		}
	}
	return -1;
}

int Snake::nextStepIsPossible()//return 2 if the snake hit the other snake, 3 if he hit food
{
	char ch;
	Point next = body[0].next(direction);
	ch = theGame->getBoard(1).getChFromBoard(next.getX(),next.getY());

	if (canMove < 0)
		return 2;
	if (ch == '@' || ch == '#')
		return 2;
	if (ch >= '0' && ch <= '9')
		return 3;
	return TRUE;
}

void Snake::shoot()
{
	char ch;
	Point pos;
	if (stackSize > 0) {
		if (canMove > 0) {
			pos.set(getSnakeHead().next(direction).getX(), getSnakeHead().next(direction).getY());
			if (hitSomething(pos) == 1)
			{
				ch=theGame->getBoard(1).getChFromBoard(pos.getX(), pos.getY());
				if (ch == '@') {
					theGame->disappearSpecificSnake(0);
					theGame->canMoveSpecificSnake(0);
				}
				else if (ch == '#') {
					theGame->disappearSpecificSnake(1);
					theGame->canMoveSpecificSnake(1);
				}
			}
			else {
				for (int i = 0; i < 5;i++)
					if (!stack[i].isActive()) {
						stack[i].init(color, direction);//initialize the bullets parameters according to the appropriate snake
						stack[i].set(pos.getX(), pos.getY());
						stack[i].setActiveStatus(true);//once the bullet was shot, it's status becomes active
						stackSize--;
						break;
					}
			}
		}
	}
}

int Snake::hitSomething(Point next)//return 0 if the sanke hit himself, 1 if he hit the other snake, 2 if he hit a number
{                                  //3 if he hit his own bullet, 4 if he hit the other snake bullet
	char ch;

	ch = theGame->getBoard(1).getChFromBoard(next.getX(), next.getY());

	if (ch==symbol)
		return 0;
	else if (ch == '#' || ch == '@')
		return 1;
	else if (ch >= '0' && ch <= '9')
		return 2;
	else if (ch == '*')
	{
		for (int i = 0; i < 5; i++)
		{
			if (stack[i].isActive())
				if (next == stack[i].getPos())
					return 3;
		}
		return 4;
	}
	else return -1;
}

void Snake::disappear()
{
	Point p;
	for (int i = 0; i < size; i++) {
		body[i].draw(' ');
		p.set(body[i].getX(), body[i].getY());
		theGame->getBoard(1).insertCharToBoard(' ', p);
	}
}

void Snake::returnAfterGetShot()
{
	Point pos;
	if (canMove == 0)
	{
		do {
			pos.set(rand() % 78, rand() % 22);
		} while (!posIsOk(pos));//check if the new position of the snake is ok
		setPosition(pos.getY(), pos.getX());
		canMove = 1;
	}
}

bool Snake::posIsOk(Point pos)//check if the position of the snake after he return from shot is ok
{
	Number num;
	char ch = theGame->getBoard(1).getChFromBoard(pos.getX(), pos.getY());

	if (ch == ' ')
		return true;
	else if (ch >= '0' && ch <= '9') {
		num = theGame->getBoard(1).getNumber(pos);
		theGame->getBoard(1).removeNumber(num);
		return true;
	}
	else
		return false;
}

Bullet& Snake::findBulletByPos(Point pos)
{
	for (int i = 0; i < 5; i++)
	{
		if (stack[i].isActive())
			if (stack[i].getX() == pos.getX() && stack[i].getY() == pos.getY())
				return stack[i];
	}
	return stack[0];//not sopposed to get here
}

void Snake::unActiveAllBullets()
{
	
	for (int i = 0; i < 5; i++) {
		theGame->getBoard(1).insertCharToBoard(' ', stack[i].getPos());
		stack[i].draw(' ');
		stack[i].setActiveStatus(false);
	}
	stackSize = 5;
	canMove = 1;
}

void Snake::printStackStats()
{
	int bullets = stackSize;
	cout << '[';
	for (int i = 0; i < 5; i++) {
		if (bullets > 0) {
			cout << '*';
			bullets--;
		}
		else
			cout << ' ';
	}
	cout << ']';
}

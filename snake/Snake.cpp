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

	if (ch == '@' || ch == '#')
		return 2;
	if (ch >= '0' && ch <= '9')
		return 3;
	return TRUE;
}

void Snake::shoot()
{
	Point pos;
	if (stackSize > 0) {
		stack[--stackSize].init(color,direction);//initialize the bullets parameters according to the appropriate snake
		pos.set(getSnakeHead().getX(), getSnakeHead().getY());
		pos.move(direction);
		stack[stackSize].set(pos.getX(),pos.getY());
		stack[stackSize].setActiveStatus(true);//once the bullet was shot, it's status becomes active
	}
}

int Snake::hitSomething(Point next)//return 0 if the sanke hit himself, 1 if he hit the other snake, 2 if he hit a number
{
	char ch;

	ch = theGame->getBoard(1).getChFromBoard(next.getX(), next.getY());

	if (ch==symbol)
		return 0;
	else if (ch == '#' || ch == '@')
		return 1;
	else if (ch >= '0' && ch <= '9')
		return 2;
	else return -1;
}

//void Snake::disappear()
//{
//
//}

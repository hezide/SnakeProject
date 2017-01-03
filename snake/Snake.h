#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <cstring>
#include "Point.h"
#include "Bullet.h"

class TheSnakesGame;

class Snake {
	enum { initSize = 15 };
	int size = 3;
	Point body[initSize];
	int direction;
	char arrowKeys[5];
	Color color;
	char symbol;//the char of the snake
	TheSnakesGame* theGame;
	int score = 0;
	Bullet stack[5];
	int stackSize = 5;
	int canMove=1;
public:
	void setGame(TheSnakesGame* _theGame) {
		theGame = _theGame;
	}
	void setPosition(int y, int x);
	void setArrowKeys(const char* keys) {
		arrowKeys[0] = keys[0];
		arrowKeys[1] = keys[1];
		arrowKeys[2] = keys[2];
		arrowKeys[3] = keys[3];
		arrowKeys[4] = keys[4];
	}
	void setColor(Color c) {
		color = c;
	}
	Color getColor() {
		return color;
	}
	void move();
	int getDirection(char key);
	int getDirection() {
		return direction;
	}
	void setDirection(int dir) {
		direction = dir;
	}
	void setSymbol(char ch)
	{
		symbol = ch;
	}
	bool oppositeDir(char key)//return TRUE if the key is in the oposite direction of the snake
	{
		int dir = getDirection(key);
		if (dir % 2 == direction % 2)//check if the directions are opposite(ex. 0 is opposite to 2)
			return TRUE;
		return FALSE;

	}
	int nextStepIsPossible();//check if the next step hitting the snake himself
	Point getSnakeHead()
	{
		return body[0];
	}
	int getScore() {
		return score;
	}
	void setScore(int _score) {
		score = _score;
	}
	void setSize(int _size) {
		size = _size;
	}
	int getSize() {
		return size;
	}
	void setStackSize(int _stackSize)
	{
		stackSize = _stackSize;
	}
	int getStackSize()
	{
		return stackSize;
	}
	int getCanMove() {
		return canMove;
	}
	void setCanMove(int _canMove)
	{
		canMove = _canMove;
	}
	void shoot();//turning thelast bullet avaliable to active=true
	Bullet& getBulletFromStack(int index) {
		return stack[index];
	}
	int hitSomething(Point next);
	void disappear();
	void returnAfterGetShot();
	bool posIsOk(Point pos);
};
#endif
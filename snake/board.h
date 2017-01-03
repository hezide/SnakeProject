#ifndef _BOARD_H
#define _BOARD_H

#include <cstring>
#include "number.h"
#include "Color.h"
enum { ROWS = 20, COLS = 80, FOOD = 60 };

class Board {
	char board[ROWS][COLS + 1];
	Number food[FOOD];
	int foodSize = 0;
#include "example_board.h"
public:
	Board() {
		resetBoard();
	}

	void printBoard();
	char getChFromBoard(int x, int y)
	{
		return board[y][x];
	}
	void insertCharToBoard(char _ch, Point point)
	{
		int x, y;
		x = point.getX();
		y = point.getY();
		board[y][x] = _ch;
	}
	int getFoodSize()
	{
		return foodSize;
	}
	void setFoodSize(int size)
	{
		foodSize = size;
	}
	void insertRndNumberToFood();

	void insertNumToBoard(Number num);
	void printNumbers();
	void printSingleNumber(Number number)
	{
		gotoxy(number.getPos()[0].getX(), number.getPos()[0].getY());
		cout << number.getNum();
	}
	bool posIsOk(Point pos, int numOfDigits);//check if the position of the number is next to a snake 

	void resetBoard();
	Number& getNumber(Point pos);
	void clearHalfOfTheNumbers();
	void removeNumber(Number& numToRemove);
	Number* getNumberArr()
	{
		return food;
	}
private:
	void removeNumFromBoard(Number& numToRemove);
	void removeNumFromFood(Number& numToRemove);
};

#endif


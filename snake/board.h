#ifndef _BOARD_H
#define _BOARD_H

#include <cstring>
#include "number.h"
#include "Color.h"
#include "ReplayMission.h"

enum { ROWS = 20, COLS = 80, FOOD = 60 };

class Board {
	char board[ROWS][COLS + 1];
	Number food[FOOD];
	int foodSize = 0;
	int step = 0;
	replayMission missionToReplay;
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
	void insertCharToBoard(char _ch, Point point,Color color=WHITE)
	{
		missionToReplay.insertItemToQueue(point, _ch, step,color);
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
	void insertRndNumberToFood(int cheat=-1);
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
	Number* getNumberArr(){
		return food;
	}
	void resetReplayMission() {
		step = 0;
		missionToReplay.emptyMissionQueue();
	}
	void captureBoard() {
		missionToReplay.captureBoard(board);
	}
	void increaseStep() {
		step++;
	}
	void replayMission() {
		missionToReplay.restoreSavedMission();
	}
private:
	void removeNumFromBoard(Number& numToRemove);
	void removeNumFromFood(Number& numToRemove);
};

#endif


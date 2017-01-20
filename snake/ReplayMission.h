#ifndef _MISSION_H
#define _MISSION_H

#include "Point.h"
#include <queue>
#include "Color.h"

struct replayItem {
	Point pos;
	char ch;
	int step;
	Color color;
};

class replayMission {
	enum { ROWS = 20, COLS = 80 };
	std::queue <replayItem> replayQueue;
	std::queue <replayItem> reserveQueue;
	char capturedBoard[ROWS][COLS];

public:
	void captureBoard(const char boardToCapture[ROWS][COLS + 1]);//capture the current game board
	void insertItemToQueue(Point pos, char ch, int step,Color color);
	void emptyMissionQueue();
	void emptyReserveQueue();
	void restoreSavedMission();
	void printCapturedBoard();
};
#endif
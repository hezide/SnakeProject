#include "ReplayMission.h"

void replayMission::captureBoard(const char boardToCapture[ROWS][COLS + 1])
{
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS - 1; j++) {
			capturedBoard[i][j] = boardToCapture[i][j];
		}
	}
}

void replayMission::insertItemToQueue(Point _pos, char _ch, int _step,Color color=WHITE)
{
	replayItem itemToInsert;
	itemToInsert.ch = _ch;
	itemToInsert.pos = _pos;
	itemToInsert.step = _step;
	itemToInsert.color = color;
	replayQueue.push(itemToInsert);
}

void replayMission::emptyMissionQueue()
{
	while (!replayQueue.empty()) replayQueue.pop();
}

void replayMission::emptyReserveQueue()
{
	while (!reserveQueue.empty()) reserveQueue.pop();
}

void replayMission::restoreSavedMission()
{
	replayItem temp;
	int currStep = 0;
	printCapturedBoard();

	temp = replayQueue.front();

	while (!replayQueue.empty()) {//run until the queue is empty

		while (currStep == temp.step) {
			temp.pos.draw(temp.ch,temp.color);
			reserveQueue.push(temp);//pop from the queue to the reserve queue so we won't loose the items
			replayQueue.pop();
			if (replayQueue.size() != 0)//check if the queue is not empty
				temp = replayQueue.front();
			else//if it is empty step ++ so it will leave the while loop
				currStep++;
		}
		currStep++;
		Sleep(150);
	}
	replayQueue = reserveQueue;
	emptyReserveQueue();
}

void replayMission::printCapturedBoard()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS - 1; j++)
		{
			gotoxy(j, i);
			if (capturedBoard[i][j] == '#')
				setTextColor(YELLOW);
			if (capturedBoard[i][j] == '@')
				setTextColor(LIGHTGREEN);
			cout << capturedBoard[i][j];
			setTextColor(WHITE);
		}
	}
}

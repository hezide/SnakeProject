#ifndef _THESNAKESGAME_H_
#define _THESNAKESGAME_H_

#include "io_utils.h"
#include "Snake.h"
#include "board.h"
#include "Menu.h"
#include "Message.h"
#include "Riddles.h"


class TheSnakesGame {
	enum { ESC = 27, FIXGOTOXY = 5};
	enum{PLAYER_1_LOC_X=1,PLAYER_1_LOC_Y=1};//player 1 Name Location
	enum { PLAYER_2_LOC_X = 65, PLAYER_2_LOC_Y = 1 };//player 2 Name Location
	enum{ NUM_OF_RIDDLES = 9 };
	Snake s[2];
	Board gameBoard[1];
	int currBoard = 0;
	Menu menu;
	Message message;
	Riddles riddleArray;
	int currRiddle;
public:
	TheSnakesGame() {
		currRiddle = 0;
	}
	int getCurrBoard()
	{
		return currBoard;
	}

	Board& getBoard(int currBoard)
	{
		return gameBoard[currBoard-1];
	}
	Riddles getRiddles() {
		return riddleArray;
	}

	int getCurrRiddle()
	{
		return currRiddle;
	}
	void init(); //copy original board to actual board and set Snakes Start point
	void run(); // run 2 Snakes with Keyboard
	void mainMenu();//start main menu
	void secondaryMenu();//start secondery menu
	void findMatchingNumbers();
	void changeToNextRiddle();
	void printPlayersStats();
	void printPlayersScores();
	bool whoWins();
	Message getMessage() {
		return message;
	}
	void foodIsEaten();
	void moveBullets();
};

#endif
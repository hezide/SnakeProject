#ifndef _THESNAKESGAME_H_
#define _THESNAKESGAME_H_

#include "io_utils.h"
#include "Snake.h"
#include "board.h"
#include "Menu.h"
#include "Message.h"
#include "Riddles.h"
#include "Creature.h"
#include "flyingRows.h"
#include "flyingCols.h"

class TheSnakesGame {
	enum { ESC = 27, FIXGOTOXY = 5};
	enum { ROWS = 20, COLS = 80};
	enum{PLAYER_1_LOC_X=1,PLAYER_1_LOC_Y=1};//player 1 Name Location
	enum { PLAYER_2_LOC_X = 65, PLAYER_2_LOC_Y = 1 };//player 2 Name Location
	enum{ NUM_OF_RIDDLES = 9 ,NUM_OF_CREATURES=4};
	Snake s[2];
	Board gameBoard[1];
	int currBoard = 0;
	Menu menu;
	Message message;
	Riddles riddleArray;
	int currRiddle;
	Creature* creaturesArray[NUM_OF_CREATURES];
	flyingRows frCW, fr;
	flyingCols fcCW, fc;
public:
	TheSnakesGame() :fr(false),frCW(true),fcCW(true),fc(false){
		currRiddle = 0;
		creaturesArray[0] = &frCW;
		creaturesArray[1] = &fr;
		creaturesArray[2] = &fcCW;
		creaturesArray[3] = &fc;
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
	void checkOppositeDir(int num, char key, int dir) {
		if (!s[num].oppositeDir(key))
			s[num].setDirection(dir);
	}
	Message getMessage() {
		return message;
	}
	void foodIsEaten();
	void moveBullets();
	void moveSingleBullet(int snake,int bullet, Point pos, int direction);
	void deleteSingleBulletFromBoard(int snake, int bullet, Point Pos);
	void handleWhatIsHit(int snake,int bullet,Point pos,int direction,int hit);
	void disappearSpecificSnake(int snake);
	void canMoveSpecificSnake(int snake);
	void restoreDeadCreatures();
	void moveCreatures();
	void handleCreatureHit(int i);
	void creatureWasHit(Point nextPos);
	Bullet* findBulletInBothSnakes(Point pos);
};

#endif
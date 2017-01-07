#include "TheSnakesGame.h"
#include <Windows.h>
#include <MMSystem.h>
#include <fstream>

void TheSnakesGame::init() {
	s[0].setArrowKeys("wdsaz");
	s[1].setArrowKeys("ilkjn");
	s[0].setColor(Color::LIGHTGREEN);
	s[1].setColor(Color::YELLOW);
	s[0].setGame(this);
	s[1].setGame(this);
	s[0].setPosition(9, 10);
	s[1].setPosition(9, 70);
	s[0].setSymbol('@');
	s[1].setSymbol('#');
	s[0].setDirection(1);
	s[1].setDirection(3);
	/*INITIAL SCORE, SIZE AND STACK OF BOTH SNAKES*/
	s[0].setScore(0);
	s[1].setScore(0);
	s[0].setSize(3);
	s[1].setSize(3);
	s[0].unActiveAllBullets();
	s[1].unActiveAllBullets();

	currRiddle = 0;
	menu.routePrintMenu('b');//print a blank board
}

void TheSnakesGame::run() {
	char key=0;
	int dir,fiveMoves=0;
	Point foodPoint;
	
	riddleArray.printRiddle(currRiddle);
	hideCursor();
	do {
		printPlayersStats();
		printPlayersScores();

		if (whoWins())//check if any player get 12 points 
			break;

		if (gameBoard[0].getFoodSize() >= FOOD) {
			findMatchingNumbers();//check if theres any number answer the riddle
			Sleep(1000);
			changeToNextRiddle();//transform to the next riddle in the array
		}

		if (_kbhit()) {
			key = _getch();
			if ((dir = s[0].getDirection(key)) != -1) 
			{
				if(!s[0].oppositeDir(key))
					s[0].setDirection(dir);
			}

			else if ((dir = s[1].getDirection(key)) != -1) 
			{
				if (!s[1].oppositeDir(key))
					s[1].setDirection(dir);
			}
		}

		foodIsEaten();//checks if one of the players ate food, and pass it on to the board

		moveBullets();//move all the bullets on the screen

		s[0].returnAfterGetShot();//return the snake the the game only after 5 numbers came up
		s[0].move();

		s[1].returnAfterGetShot();//return the snake the the game only after 5 numbers came up
		s[1].move();

		Sleep(100);

		fiveMoves++;
		if (fiveMoves % 5 == 0) {//check if we need to add another number to board
			this->getBoard(1).insertRndNumberToFood();
			s[0].setCanMove(s[0].getCanMove() + 1);
			s[1].setCanMove(s[1].getCanMove() + 1);
		}


	} while (key != ESC);

	if (key == ESC) {//pause the game and go to secondary menu
		message.routePrintMessage('p');//print game paused
		secondaryMenu();
	}
}

void TheSnakesGame::mainMenu() {

	char selection;
	hideCursor();
	gameBoard->resetBoard();//clear the board
	selection = menu.routePrintMenu('m');
	switch (selection) {
		//print instructions to the screen
	case '1':
		message.routePrintMessage('i');
		mainMenu();
		break;
		//Start New game
	case '2':

		PlaySound(NULL, NULL, NULL);
		currRiddle = 0;
		getBoard(1).printBoard();//print blank board in order to remove the welcome message
		init();
		run();
		break;
		//Exit
	case '9':
		message.routePrintMessage('b');// BYE BYE MESSAGE
		break;
	default:
		mainMenu();//invalid input
	}
}

void TheSnakesGame::secondaryMenu() {
	char selection;
	selection = menu.routePrintMenu('s');
	switch (selection) {
	//Exit game
	case '1':
		message.routePrintMessage('b');// BYE BYE MESSAGE
		break;
	//Go to Main menu
	case '2':
		message.routePrintMessage('w');//print welcome message
		mainMenu();//go to main menu
		break;
	//continue game
	case '3':
		gameBoard->printBoard();//print the board again because it has the paused message printed
		menu.routePrintMenu('b');
		run();
		break;
	//restart stage
	case '4':
		gameBoard[0].clearHalfOfTheNumbers();
		s[0].unActiveAllBullets();
		s[1].unActiveAllBullets();
		gameBoard->printBoard();//print the board again because it has the paused message printed
		menu.routePrintMenu('b');
		run();
		break;
	//Start new stage
	case '5':
		currRiddle = (currRiddle + 1) % NUM_OF_RIDDLES;
		gameBoard[0].clearHalfOfTheNumbers();
		s[0].unActiveAllBullets();
		s[1].unActiveAllBullets();
		gameBoard->printBoard();//print the board again because it has the paused message printed
		menu.routePrintMenu('b');
		run();
		break;
	//start New Game
	case '6':
		init();
		gameBoard[0].resetBoard();
		gameBoard[0].printBoard();
		run();
		break;
	default:
		secondaryMenu();//invalid input
	}
}

void TheSnakesGame::findMatchingNumbers(){
	Number temp;
	bool flag = false;
	setTextColor(Color::RED);
	for (int i = 0; i < gameBoard[0].getFoodSize(); i++)
	{
		temp = gameBoard[0].getNumberArr()[i];
		if (riddleArray.solveRiddle(currRiddle, temp.getNum()))
		{
			flag = true;
			gotoxy(temp.getPos()[0].getX(), temp.getPos()[0].getY());
			cout << temp.getNum();
		}
	}
	setTextColor(Color::WHITE);
	if (!flag)
	{
		message.routePrintMessage('n');//print no matching numbers
	}
}

void TheSnakesGame::changeToNextRiddle()
{
	s[0].unActiveAllBullets();
	s[1].unActiveAllBullets();
	currRiddle = (currRiddle + 1 )%NUM_OF_RIDDLES;
	riddleArray.printRiddle(currRiddle);
	gameBoard[0].clearHalfOfTheNumbers();
	Sleep(500);
}

void TheSnakesGame::printPlayersStats()
{

	gotoxy(PLAYER_1_LOC_X,PLAYER_1_LOC_Y-FIXGOTOXY);
	setTextColor(s[0].getColor());
	cout << "Player 1:";
	gotoxy(PLAYER_1_LOC_X, PLAYER_1_LOC_Y - FIXGOTOXY+1);
	setTextColor(s[0].getColor());
	cout << "Stack:";
	gotoxy(PLAYER_2_LOC_X,PLAYER_2_LOC_Y- FIXGOTOXY);
	setTextColor(s[1].getColor());
	cout << "Player 2:";
	gotoxy(PLAYER_2_LOC_X, PLAYER_2_LOC_Y - FIXGOTOXY+1);
	setTextColor(s[1].getColor());
	cout << "Stack:";
	setTextColor(Color::WHITE);
}

void TheSnakesGame::printPlayersScores()
{
	gotoxy(PLAYER_1_LOC_X + 10, PLAYER_1_LOC_Y-FIXGOTOXY);
	setTextColor(s[0].getColor());
	cout << s[0].getScore();

	gotoxy(PLAYER_1_LOC_X + 6, PLAYER_1_LOC_Y - FIXGOTOXY+1);
	setTextColor(s[0].getColor());
	s[0].printStackStats();

	gotoxy(PLAYER_2_LOC_X + 10, PLAYER_2_LOC_Y - FIXGOTOXY);
	setTextColor(s[1].getColor());
	cout << s[1].getScore();

	gotoxy(PLAYER_2_LOC_X + 6, PLAYER_2_LOC_Y - FIXGOTOXY+1);
	setTextColor(s[1].getColor());
	s[1].printStackStats();

	setTextColor(Color::WHITE);
}

bool TheSnakesGame::whoWins() {
	
	if (s[0].getScore() == 12) {
		message.routePrintMessage('x');
		Sleep(800);
		message.routePrintMessage('w');//print welcome message
		mainMenu();
		return true;
	}
	else if (s[1].getScore() == 12) {
		message.routePrintMessage('y');
		Sleep(800);
		message.routePrintMessage('w');//print welcome message
		mainMenu();
		return true;
	}
	return false;
}

void TheSnakesGame::foodIsEaten()
{
	for (int i = 0; i < 2; i++)
	{
		if (s[i].nextStepIsPossible() == 3)//there is a number in the next position
		{
			Number& eatenNum = gameBoard[0].getNumber(s[i].getSnakeHead().next(s[i].getDirection()));
			if (riddleArray.solveRiddle(currRiddle, eatenNum.getNum())) {//check if the snake ate a good number
				s[i].setSize(s[i].getSize() + 1);//increase the size of the snake
				s[i].setScore(s[i].getScore() + 1);//increase the score of the snake


				if (std::ifstream("R2D2-yeah.wav"))
					PlaySound(TEXT("R2D2-yeah.wav"), NULL, SND_ASYNC);
				else
					PlaySound(TEXT("R2D2-yeah.wav"), NULL, SND_NODEFAULT);
				message.routePrintMessage('1' + i);
				Sleep(1000);
			}
			else {
				s[(i + 1) % 2].setSize(s[(i + 1) % 2].getSize() + 1);//increase the size of the other snake
				s[(i + 1) % 2].setScore(s[(i + 1) % 2].getScore() + 1);//increase the score of the other snake

				if (std::ifstream("badFood.wav"))
					PlaySound(TEXT("badFood.wav"), NULL, SND_ASYNC);
				else
					PlaySound(TEXT("badFood.wav"), NULL, SND_NODEFAULT);
				message.routePrintMessage('3' + i);
				Sleep(1000);
				gameBoard[0].printBoard();
				findMatchingNumbers();
			}
			gameBoard[0].removeNumber(eatenNum);
			changeToNextRiddle();//change to the next riddle in the array
		}
	}
}

void TheSnakesGame::moveBullets(){
	Point nextPos, pos;
	int hit;
	int direction;
	for (int i = 0; i < 2; i++) {//each bullet move twice
		for (int i = 0; i <= 1; i++) {//snake
			for (int j = 0; j < 5; j++) {//bullets of each snake
				if (s[i].getBulletFromStack(j).isActive()) {

					direction = s[i].getBulletFromStack(j).getDirection();
					pos.set(s[i].getBulletFromStack(j).getX(), s[i].getBulletFromStack(j).getY());
					nextPos = pos.next(direction);

					hit = s[i].hitSomething(nextPos);

					handleWhatIsHit(i, j, pos, direction, hit);
				}
			}
		}
	}
}

void TheSnakesGame::moveSingleBullet(int snake,int bullet, Point pos, int direction)
{
	Point nextPos = pos.next(direction);
	gameBoard[0].insertCharToBoard(' ', pos);
	s[snake].getBulletFromStack(bullet).draw(' ');

	s[snake].getBulletFromStack(bullet).move(direction);
	gameBoard[0].insertCharToBoard('*', nextPos);
	setTextColor(s[snake].getColor());
	s[snake].getBulletFromStack(bullet).draw('*');
	setTextColor(Color::WHITE);
}

void TheSnakesGame::deleteSingleBulletFromBoard(int snake, int bullet, Point pos)
{
	gameBoard[0].insertCharToBoard(' ', pos);
	s[snake].getBulletFromStack(bullet).draw(' ');
}

void TheSnakesGame::handleWhatIsHit(int snake, int bullet, Point pos, int direction, int hit) {
	Point nextPos = pos.next(direction);
	if (hit == -1)//next step is possible
		moveSingleBullet(snake, bullet, pos, direction);

	else if (hit == 0) {//s[i] hit himself
		s[snake].setCanMove(-5);
		s[snake].disappear();
		s[snake].getBulletFromStack(bullet).setActiveStatus(false);
		gameBoard[0].insertCharToBoard(' ', pos);
		s[snake].getBulletFromStack(bullet).draw(' ');
	}
	else if (hit == 1) {//s[i] hit the other snake
		s[(snake + 1) % 2].setCanMove(-5);
		s[(snake + 1) % 2].disappear();
		s[snake].setStackSize(s[snake].getStackSize() + 1);
		s[snake].getBulletFromStack(bullet).setActiveStatus(false);
		deleteSingleBulletFromBoard(snake, bullet, pos);
		//std::swap(s[snake].getBulletFromStack(bullet), s[snake].getBulletFromStack(s[snake].getStackSize() - 1));
	}
	else if (hit == 2) {//s[i] hit a number
		getBoard(1).removeNumber(getBoard(1).getNumber(pos.next(direction)));
		s[snake].getBulletFromStack(bullet).setActiveStatus(false);
		deleteSingleBulletFromBoard(snake, bullet, pos);
	}
	else if (hit == 3) {//s[i] hit is own bullet

		if (s[snake].getBulletFromStack(bullet).getDirection() != s[snake].findBulletByPos(nextPos).getDirection()) {
			//first Bullet-the hitting bullet
			s[snake].getBulletFromStack(bullet).setActiveStatus(false);
			deleteSingleBulletFromBoard(snake, bullet, pos);
			//second Bullet
			gameBoard[0].insertCharToBoard(' ', nextPos);
			s[snake].findBulletByPos(nextPos).draw(' ');
			s[snake].findBulletByPos(nextPos).setActiveStatus(false);
		}
		else
			moveSingleBullet(snake, bullet, pos, direction);
	}
	else if (hit == 4) {//s[i] hit the other snake bullet
						//s[i]
		s[snake].setStackSize(s[snake].getStackSize() + 1);
		s[snake].getBulletFromStack(bullet).setActiveStatus(false);
		deleteSingleBulletFromBoard(snake, bullet, pos);
		//std::swap(s[snake].getBulletFromStack(bullet), s[snake].getBulletFromStack(s[snake].getStackSize() - 1));
		//s[(i+1)%2]
		s[(snake + 1) % 2].setStackSize(s[(snake + 1) % 2].getStackSize() + 1);
		deleteSingleBulletFromBoard((snake + 1) % 2, bullet, pos);
		s[(snake + 1) % 2].findBulletByPos(nextPos).setActiveStatus(false);
		//std::swap(s[(snake + 1) % 2].getBulletFromStack(bullet), s[(snake + 1) % 2].getBulletFromStack(s[(snake + 1) % 2].getStackSize() - 1));
	}
}

void TheSnakesGame::disappearSpecificSnake(int snake)
{
	s[snake].disappear();
}

void TheSnakesGame::canMoveSpecificSnake(int snake)
{
	s[snake].setCanMove(-5);
}





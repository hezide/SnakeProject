#include "board.h"

void Board::printBoard() {
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS-1; j++)
		{
			gotoxy(j, i);
			if (board[i][j] == '#')
				setTextColor(YELLOW);
			if (board[i][j] == '@')
				setTextColor(LIGHTGREEN);
			cout << board[i][j];
			setTextColor(WHITE);
		}
	}
}


void Board::insertRndNumberToFood(int cheat)
{
	Point pos;
	int numOfDigits, numToInsert, groupOfNumbers;
	groupOfNumbers = rand() % 3;

	/*probability of randing numbers*/
	switch (groupOfNumbers) {
	case 0:
		numToInsert = rand() % 26;
		break;
	case 1:
		numToInsert = rand() % 56 + 26;
		break;
	case 2:
		numToInsert = rand() % 88 + 82;
		break;
	}
	if (cheat != -1)
		numToInsert = cheat;
	food[foodSize].setNum(numToInsert);

	numOfDigits = food[foodSize].calcNumOfDigits();
	food[foodSize].setNumOfDigits(numOfDigits);

	do {
		pos.set(rand() % 78, rand() % 22);
	} while (!posIsOk(pos, numOfDigits));//check if the position of all the digits is ok
	food[foodSize].set3Pos(pos, numOfDigits);
	insertNumToBoard(food[foodSize]);
	foodSize++;

}

void Board::insertNumToBoard(Number num)
{
	int tempNum = num.getNum();
	for (int i = num.getNumOfDigits(); i >0; i--)
	{
		insertCharToBoard(tempNum % 10 + '0', num.getPos()[i - 1]);
		tempNum /= 10;
	}
	printSingleNumber(food[foodSize]);
}

void Board::printNumbers()
{
	for (int i = 0; i < foodSize; i++) {
		if (food[i].getNum() != -1)
		{
			gotoxy(food[i].getPos()[0].getX(), food[i].getPos()[0].getY());
			cout << food[i].getNum();
		}
		
	}
}

bool Board::posIsOk(Point pos, int numOfDigits)
{
	char a, b;
	for (int i = 0; i < numOfDigits; i++)//loop to check the surroundings of each digit
	{
		for (int j = -1; j < 2; j++)//loop to check up,down,right,left
		{
			a = getChFromBoard(pos.getX() + i, pos.getY() + j);
			b = getChFromBoard(pos.getX() + j + i, pos.getY());
			if (a != ' ' || b != ' ')
				return FALSE;
		}
	}
	return TRUE;
}

void Board:: resetBoard(){
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++)
			board[i][j] = board_example[i][j];
		board[i][COLS] = '\0';
	}
}

Number& Board::getNumber(Point pos)
{
	int i = 0;
	for (i = 0; i < foodSize; i++) {//loop to find the number in the food array
		for (int j = 0; j < food[i].getNumOfDigits(); j++) {//loop to find the number using the position
			if (food[i].getPos()[j] == pos) {
				return food[i];
			}
		}
	}
	return food[i];
}

void Board::clearHalfOfTheNumbers()
{
	int numOfIterations = foodSize / 2;
	int randIndex;
	for (int i = 0; i < numOfIterations; i++)
	{
		randIndex = rand() % foodSize;
		removeNumber(food[randIndex]);
	}
	printBoard();

}

void Board::removeNumber(Number & numToRemove)
{
	removeNumFromBoard(numToRemove);
	removeNumFromFood(numToRemove);
}

Color Board::getColorOfTheCh(char ch)
{
	switch (ch) {
	case '#':
		return YELLOW;
		break;
	case '@':
		return LIGHTGREEN;
		break;
	case'!':
		
		break;
	case'$':

		break;
	case '%':

		break;
	}
}

void Board::removeNumFromBoard(Number & numToRemove)
{
	/*REMOVE THE NUM FROM THE BOARD AND PRINT SPACE*/
	int numOfDigits = numToRemove.getNumOfDigits();
	int x, y;
	x = numToRemove.getPos()[0].getX();
	y = numToRemove.getPos()[0].getY();
	gotoxy(x, y);

	for (int i = 0; i < numOfDigits ; i++) {
		board[y][x + i] = ' ';
		cout << ' ';
	}
}

void Board::removeNumFromFood(Number & numToRemove)
{
	numToRemove = food[foodSize-1];
	food[foodSize-1].setNum(-1);
	food[foodSize-1].resetPos();
	food[foodSize - 1].setNumOfDigits(0);
	foodSize--;
}

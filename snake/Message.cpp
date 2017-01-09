#include "Message.h"

void Message::routePrintMessage(char type) {
	//w=welcome, p=game paused, i=instructions, b= bye bye, x= player 1 wins, y=player 2 wins
	switch (type) {
		//welcomeMessage
	case 'w':
		printFullSizeMessage(welcome);
		break;
	case 'p':
		printSmallSizeMessage(gamePaused);
		break;
	case 'i':
		printFullSizeMessage(instructions);
		break;
	case 'b':
		printSmallSizeMessage(byeBye);
		gotoxy(FULL_MESSAGE_ROWS,FULL_MESSAGE_ROWS-1);//move the cursor to the end of the cmd window
		break;
	case 'n':
		printSmallSizeMessage(noMatchingNumbers);
		break;
	case 'x':
		printSmallSizeMessage(player1Wins);
		break;
	case 'y':
		printSmallSizeMessage(player2Wins);
		break;
	case '1':
		printSmallSizeMessage(player1AnsweredCorrectly);
		break;
	case '2':
		printSmallSizeMessage(player2AnsweredCorrectly);
		break;
	case '3':
		printSmallSizeMessage(player1AnsweredWrong);
		break;
	case '4':
		printSmallSizeMessage(player2AnsweredWrong);
		break;
	}
	Sleep(500);
}

void Message::printFullSizeMessage(const char message[FULL_MESSAGE_ROWS][FULL_MESSAGE_COLS + 1]) {
	for (int i = 0; i < FULL_MESSAGE_ROWS; i++)
	{
		for (int j = 0; j < FULL_MESSAGE_COLS; j++)
		{
			gotoxy(j, i);
			cout << message[i][j];
		}
	}
}

void Message::printSmallSizeMessage(const char message[SMALL_MESSAGE_ROWS][SMALL_MESSAGE_COLS + 1]) {
	for (int i = 0; i < SMALL_MESSAGE_ROWS; i++)
	{
		for (int j = 0; j < SMALL_MESSAGE_COLS; j++)
		{
			gotoxy(j + FIX_GOTO_X_Y_COLS, i + FIX_GOTO_X_Y_ROWS);
			cout << message[i][j];
		}
	}
}
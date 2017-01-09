#ifndef _MESSAGE_
#define _MESSAGE_

#include "Point.h"

class Message {
	enum { FULL_MESSAGE_ROWS = 20, FULL_MESSAGE_COLS = 80, SMALL_MESSAGE_ROWS=5,SMALL_MESSAGE_COLS=28};
	enum {FIX_GOTO_X_Y_ROWS=7, FIX_GOTO_X_Y_COLS=26};//enum of small message location
	const char gamePaused[SMALL_MESSAGE_ROWS][SMALL_MESSAGE_COLS+1]{
	//	          10        20         
	//	 0123456789012345678901234567
		"++++++++++++++++++++++++++++", // 0
		"+                          +", // 1
		"+       GAME PAUSED        +", // 2
		"+                          +", // 3
		"++++++++++++++++++++++++++++"  // 4
	//   0123456789012345678901234567
	};
	const char byeBye[SMALL_MESSAGE_ROWS][SMALL_MESSAGE_COLS+1]{
		//	          10        20         
		//	 0123456789012345678901234567
		"++++++++++++++++++++++++++++", // 0
		"+                          +", // 1
		"+         BYE BYE!         +", // 2
		"+                          +", // 3
		"++++++++++++++++++++++++++++"  // 4
	//   0123456789012345678901234567
	};
	const char noMatchingNumbers[SMALL_MESSAGE_ROWS][SMALL_MESSAGE_COLS + 1]{
		//	          10        20         
		//	 0123456789012345678901234567
		"++++++++++++++++++++++++++++", // 0
		"+THERE WERE NO MATCHING    +", // 1
		"+  NUMBERS, CHANGING RIDDLE+", // 2
		"+                          +", // 3
		"++++++++++++++++++++++++++++"  // 4
	//   0123456789012345678901234567
	};
	const char welcome[FULL_MESSAGE_ROWS][FULL_MESSAGE_COLS+1]{
		//           10        20        30        40        50        60        70       79
		//  01234567890123456789012345678901234567890123456789012345678901234567890123456789
		"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++", // 0
		"+                 _______..__   __.      ___       __  ___  _______            +",
		"+                /       ||  \\ |  |     /   \\     |  |/  / |   ____|           +",
		"+               |   (----`|   \\|  |    /  ^  \\    |  '  /  |  |__              +",
		"+                \\   \\    |  . `  |   /  /_\\  \\   |    <   |   __|             +",
		"+            .----)   |   |  |\\   |  /  _____  \\  |  .  \\  |  |____            +",
		"+            |_______/    |__| \\__| /__/     \\__\\ |__|\\__\\ |_______|           +",
		"+                                                                              +",
		"+            ____    __    ____  ___      .______          _______.            +",
		"+            \\   \\  /  \\  /   / /   \\     |   _  \\        /       |            +",
		"+             \\   \\/    \\/   / /  ^  \\    |  |_)  |      |   (----`            +",
		"+              \\            / /  /_\\  \\   |      /        \\   \\                +",
		"+               \\    /\\    / /  _____  \\  |  |\\  \\----.----)   |               +",
		"+                \\__/  \\__/ /__/     \\__\\ | _| `._____|_______/                +",
		"+                                                                              +",
		"+                                                                              +",
		"+                                                                              +",
		"+                                                                              +",
		"+  Hezi Debby                                                   Yair Karshi    +", // 22 
		"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"  // 23
																							//   01234567890123456789012345678901234567890123456789012345678901234567890123456789 
	};
	const char instructions[FULL_MESSAGE_ROWS][FULL_MESSAGE_COLS + 1]{
	//	          10        20        30        40        50        60        70       79
	//	 01234567890123456789012345678901234567890123456789012345678901234567890123456789
		"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++", // 0
		"+  GAME INSTRUCTIONS:                                                          +", // 1
		"+                                                                              +", // 2
		"+  - This is a competitive math snake game.                                    +", // 3
		"+                                                                              +", // 4
		"+  - Each one of the players need to collect number according to the           +", // 5
		"+    riddle at the top of the screen, for exemple \"Collect even number\",       +", // 6
		"+    the first player that will collect a matching number get a point.         +", // 7
		"+                                                                              +", // 8
		"+  - Each time one of the players collect a number the riddle will be change.  +", // 9
		"+                                                                              +", // 10
		"+  - The first player who get 12 point win the game.                           +", // 11
		"+                                                                              +", // 12
		"+  - Be carful not to get stuck in your self or you will stay stuck to the     +", // 13
		"+    end of the game.                                                          +", // 14
		"+                                                                              +", // 15
		"+  - Player 1 keys: w=Up, d=Right, x=Down, a=Left, z=shoot                     +", // 16
		"+                                                                              +", // 17
		"+  - Player 2 keys: i=Up, l=Right, m=Down, j=Left, n=shoot                     +", // 18
		"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"  // 23
	//   01234567890123456789012345678901234567890123456789012345678901234567890123456789   
	};
	const char player1Wins[SMALL_MESSAGE_ROWS][SMALL_MESSAGE_COLS + 1]{
		//	          10        20         
		//	 0123456789012345678901234567
		"++++++++++++++++++++++++++++", // 0
		"+      PLAYER 1 WINS!      +", // 1
		"+         GOOD JOB!        +", // 2
		"+                          +", // 3
		"++++++++++++++++++++++++++++"  // 4
    //   0123456789012345678901234567
	};
	const char player2Wins[SMALL_MESSAGE_ROWS][SMALL_MESSAGE_COLS + 1]{
		//	          10        20         
		//	 0123456789012345678901234567
		"++++++++++++++++++++++++++++", // 0
		"+      PLAYER 2 WINS!      +", // 1
		"+         GOOD JOB!        +", // 2
		"+                          +", // 3
		"++++++++++++++++++++++++++++"  // 4
    //   0123456789012345678901234567
	};
	const char player1AnsweredCorrectly[SMALL_MESSAGE_ROWS][SMALL_MESSAGE_COLS + 1]{
		//	          10        20         
		//	 0123456789012345678901234567
		"++++++++++++++++++++++++++++", // 0
		"+         PLAYER 1         +", // 1
		"+     Answered Correctly!  +", // 2
		"+                          +", // 3
		"++++++++++++++++++++++++++++"  // 4
										//   0123456789012345678901234567
	};
	const char player2AnsweredCorrectly[SMALL_MESSAGE_ROWS][SMALL_MESSAGE_COLS + 1]{
		//	          10        20         
		//	 0123456789012345678901234567
		"++++++++++++++++++++++++++++", // 0
		"+         PLAYER 2         +", // 1
		"+     Answered Correctly!  +", // 2
		"+                          +", // 3
		"++++++++++++++++++++++++++++"  // 4
										//   0123456789012345678901234567
	};
	const char player1AnsweredWrong[SMALL_MESSAGE_ROWS][SMALL_MESSAGE_COLS + 1]{
		//	          10        20         
		//	 0123456789012345678901234567
		"++++++++++++++++++++++++++++", // 0
		"+         PLAYER 1         +", // 1
		"+      Answered Wrong!     +", // 2
		"+                          +", // 3
		"++++++++++++++++++++++++++++"  // 4
										//   0123456789012345678901234567
	};
	const char player2AnsweredWrong[SMALL_MESSAGE_ROWS][SMALL_MESSAGE_COLS + 1]{
		//	          10        20         
		//	 0123456789012345678901234567
		"++++++++++++++++++++++++++++", // 0
		"+         PLAYER 2         +", // 1
		"+      Answered Wrong!     +", // 2
		"+                          +", // 3
		"++++++++++++++++++++++++++++"  // 4
										//   0123456789012345678901234567
	};
public:
	void routePrintMessage(char type);
private:
	//everyone who wants to print a message goes through routePrintMessage
	void printFullSizeMessage(const char message[FULL_MESSAGE_ROWS][FULL_MESSAGE_COLS + 1]);
	void printSmallSizeMessage(const char message[SMALL_MESSAGE_ROWS][SMALL_MESSAGE_COLS + 1]);
};


#endif
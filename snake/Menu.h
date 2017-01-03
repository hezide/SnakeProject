#ifndef _MENU
#define _MENU

#include "Point.h"

class Menu {
	enum { ROWS = 6, COLS = 80, FIXGOTOXY = 5 };
	const char* mainMenu[6] = {
		//	          10        20        30        40        50        60        70       79
		//	 01234567890123456789012345678901234567890123456789012345678901234567890123456789
		"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++", // 0
		"+                        [1] Display instructions                              +", // 1
		"+                        [2] Start Game                                        +", // 2
		"+                        [9] Exit                                              +", // 3
		"+                        Please enter your selection here:                     +", // 4
		"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"  // 5
		//   01234567890123456789012345678901234567890123456789012345678901234567890123456789
	};
	const char* secMenu[6] = {
		//	          10        20        30        40        50        60        70       79
		//	 01234567890123456789012345678901234567890123456789012345678901234567890123456789
			"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++", // 0
			"+      [1] Exit                             [4] Restart Stage                  +", // 1
			"+      [2] Return to Main Menu              [5] Start New Stage                +", // 2
			"+      [3] Continue Game                    [6] Start New Game                 +", // 3
			"+      Please enter your selection here:                                       +", // 4
			"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"  // 5
		//   01234567890123456789012345678901234567890123456789012345678901234567890123456789
	};
	const char* blankMenu[6] = {
	//	          10        20        30        40        50        60        70       79
	//	 01234567890123456789012345678901234567890123456789012345678901234567890123456789
		"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++", // 0
		"+                                                                              +", // 1
		"+                                                                              +", // 2
		"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++", // 3
		"+                                                                              +", // 4
		"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"  // 5
	//   01234567890123456789012345678901234567890123456789012345678901234567890123456789
	};
	Point mainMenuSelectorPosition = { 58,4 };//main menu cursor position
	Point secondaryMenuSelectorPosition = { 40,4 };//sec menu cursor position
public:
	// gets requested menu from user and sends it to printMenu function.
	char routePrintMenu(char menuChar) {
		//m=Main, s=Secondary b=blank
		switch (menuChar) {
		case 'm':
			printMenu(mainMenu);
			return mainMenuGetInput();
			break;
		case's':
			printMenu(secMenu);
			return secondaryMenuGetInput();
			break;
		case 'b':
			printMenu(blankMenu);
			break;
		}
		return NULL;//should never reach here;
	} 
	char mainMenuGetInput();//get input for the main menu and return it to the game
	char secondaryMenuGetInput();//get input for the secondary menu and return it to the game

private:
	//print menu goes through routePrintMenu
	void printMenu(const char** menu);
};
#endif
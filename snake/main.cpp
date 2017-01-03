#include <windows.h>
#include <iostream>
#include<fstream>
using namespace std;

#include "TheSnakesGame.h"
#include "board.h"

int main() {
	TheSnakesGame game;//a game is created and a welcome message is displayed(in the game's constructor
	if(std::ifstream("star_wars_main.wav"))
		PlaySound(TEXT("star_wars_main.wav"), NULL,SND_ASYNC);
	else
		PlaySound(TEXT("star_wars_main.wav"), NULL, SND_NODEFAULT);
	game.getMessage().routePrintMessage('w');//print welcome message
	game.mainMenu();
}
#include "Menu.h"

void Menu::printMenu(const char** menu) {
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			gotoxy(j, i - FIXGOTOXY);//fixed because -FIXEDGOTOXY is the menu's location.
			cout << menu[i][j];
		}
	}
}

char Menu::mainMenuGetInput() {

	char selection;
	
		/*place the cursor in the currect location*/
		gotoxy(mainMenuSelectorPosition.getX(), mainMenuSelectorPosition.getY() - FIXGOTOXY);
		cout << "      ";//erase whatever is there and then return to the same position
		gotoxy(mainMenuSelectorPosition.getX(), mainMenuSelectorPosition.getY() - FIXGOTOXY);
		cin >> selection;

		switch (selection) {
		case '1':
			return selection;
			break;
		case '2':
			return selection;
			break;
		case '9':
			return selection;
			break;
		default:
			mainMenuGetInput();
		}
		return NULL;//should never reach here;
}

char Menu::secondaryMenuGetInput() {

	char selection;

	/*place the cursor in the currect location*/
	gotoxy(secondaryMenuSelectorPosition.getX(), secondaryMenuSelectorPosition.getY() - FIXGOTOXY);
	cout << "      ";//erase whatever is there and then return to the same position
	gotoxy(secondaryMenuSelectorPosition.getX(), secondaryMenuSelectorPosition.getY() - FIXGOTOXY);
	cin >> selection;

	switch (selection) {
	case '1':
		return selection;
		break;
	case '2':
		return selection;
		break;
	case '3':
		return selection;
		break;
	case '4':
		return selection;
	case '5':
		return selection;
	case '6':
		return selection;
	default:
		secondaryMenuGetInput();
	}
	return NULL;//should never reach here;
}
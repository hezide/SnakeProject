#include "Riddles.h"

bool Riddles::solveRiddle(int numOfRiddle, int numToSolve)
{
	switch (numOfRiddle) {
	case 0:
		//return solveComplexExercise(numToSolve);
		break;
	case 1:
		return solveIsEven(numToSolve);
		break;
	case 2:
		return solveIsPrimeNumber(numToSolve);
		break;
	case 3:
		return solveNumIsDivideBy3(numToSolve);
		break;
	case 4:
		return solveNumIsMultipleOf7(numToSolve);
		break;
	case 5:
		return solveNumIsPowerOfIntegerNumber(numToSolve);
		break;
	case 6:
		return solveNumIsDivideBy4(numToSolve);
		break;
	case 7:
		return solveNumIsDivideBy5WithCarry2(numToSolve);
		break;
	case 8:
		return collectPowOf4(numToSolve);
		break;
	case 9:
		return collectNumberThatCanDivide16(numToSolve);
		break;
	default:
		return false;
	}
}

void Riddles::printBlock()
{
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < COLS; j++) {
			gotoxy(j, i - FIXGOTOXY);//fixed because -FIXEDGOTOXY is the menu's location.
			cout << riddleblock[i][j];
		}
	}
}

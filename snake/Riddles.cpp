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

void Riddles::createComplexExercise()
{
	char op1, op2;
	int left, mid, right, sol;
	int leftMid, midRight;
	int numToSolve;
	bool isLegalExercise;

	do {
		op1 = getRandOperator();//get the first operator
		op2 = getRandOperator();//get the second operator
		left = rand() % NUMRANGE;//get random number

		left = getRandomNumber();
		mid = getRandomNumber(op1, left);
		right = getRandomNumber(op2, mid);

		/*CALCULATE THE EXERCISE BY LEGAL MATH ORDER*/
		if (op1 == '*' || op1 == '/') {
			leftMid = calcTwoNums(left, mid, op1);
			sol = calcTwoNums(leftMid, right, op2);
		}
		else if (op2 == '*' || op2 == '/') {
			midRight = calcTwoNums(mid, right, op2);
			sol = calcTwoNums(sol, midRight, op1);
		}
		else {
			leftMid = calcTwoNums(left, mid, op1);
			sol = calcTwoNums(leftMid, right, op2);
		}
		numToSolve=randWhiceNumShouldBeSolved(left, mid, right, sol);
		isLegalExercise = checkIfExerciseIsLegal();
	}while(!isLegalExercise)


}
int Riddles::getRandomNumber(char op = ' ',int before=0) {
	int num;
	if (op == '/')
		num = rand() % before;//if the operator is / we should rand a smaller number so we won't get a fraction
	else
		num = rand() % NUMRANGE;
	return num;
}

char Riddles::getRandOperator()
{
	short int num;
	num = rand() % 4;
	switch (num) {
	case 0:
		return '+';
		break;
	case 1:
		return '-';
		break;
	case 2:
		return '*';
		break;
	case 3:
		return '/';
		break;
	}
}

int Riddles::calcTwoNums(int num1, int num2, char op)
{
	switch (op) {
	case '+':
		return num1 + num2;
		break;
	case '-':
		return num1 - num2;
		break;
	case '*':
		return num1 * num2;
		break;
	case '/':
		return num1 / num2;
		break;
	}
}

bool Riddles::checkIfExerciseIsLegal(int numToSolve)
{
	if (numToSolve<0 || numToSolve>NUMRANGE)
		return false;
	else
		return true;
}

int Riddles::randWhiceNumShouldBeSolved(int left, int mid, int right, int sol)
{
	short int num;
	num = rand() % 4;
	switch (num) {
	case 0:
		return left;
		break;
	case 1:
		return mid;
		break;
	case 2:
		return right;
		break;
	case 3:
		return sol;
		break;
	}
}

#include "Riddles.h"

bool Riddles::solveRiddle(int numOfRiddle, int numToSolve)
{
	switch (numOfRiddle) {
	case 0:
		if (numToSolve == exerciseSolution)
			return true;
		else
			return false;
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
	int* numToSolve=NULL;
	bool isLegalExercise;

	do {
		op1 = getRandOperator();//get the first operator
		op2 = getRandOperator();//get the second operator
		left = rand() % NUMRANGE;//get random number

		left = getRandomNumber();
		mid = getRandomNumber(op1, left);
		right = getRandomNumber(op2, mid);
		sol = 0;
		isLegalExercise = true;
		/*CALCULATE THE EXERCISE BY LEGAL MATH ORDER*/
		{
			if (op1 == '*' || op1 == '/') {
				
				if (op1 == '/')
					isLegalExercise = divisionCase(left, mid);

				if (isLegalExercise) {
					leftMid = calcTwoNums(left, mid, op1);
					if (op2 == '/')
						isLegalExercise = divisionCase(leftMid, right);

					if (isLegalExercise)
						sol = calcTwoNums(leftMid, right, op2);
				}
			}
			else if (op2 == '*' || op2 == '/') {

				if (op2 == '/')
					isLegalExercise = divisionCase(mid, right);
				if (isLegalExercise) {
					midRight = calcTwoNums(mid, right, op2);

					if (op2 == '/')
						isLegalExercise = divisionCase(left, midRight);

					if (isLegalExercise)
						sol = calcTwoNums(left, midRight, op1);
				}
			}
			else {
				leftMid = calcTwoNums(left, mid, op1);
				sol = calcTwoNums(leftMid, right, op2);
			}
		}
		numToSolve=randWhiceNumShouldBeSolved(&left, &mid, &right, &sol);
		if (isLegalExercise)
			isLegalExercise = checkIfExerciseIsLegal(*numToSolve,sol);

	} while (!isLegalExercise);
	exerciseSolution = *numToSolve;
	createTheExcerciseString(&left, &mid, &right, &sol, numToSolve, op1, op2);
}

int Riddles::getRandomNumber(char op ,int before) {
	int num;
	if (op == '/' && before!=0)
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
	default:
		return 0;
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
	default:
		return 0;
		break;
	}
}

bool Riddles::checkIfExerciseIsLegal(const int numToSolve,int sol)
{
	if (numToSolve<0 || numToSolve>NUMRANGE || sol<0||sol>NUMRANGE)
		return false;
	else
		return true;
}

int* Riddles::randWhiceNumShouldBeSolved(int* left, int* mid, int* right, int* sol)
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
	default:
		return 0;
		break;
	}
}

void Riddles::createTheExcerciseString(int * left, int * mid, int * right, int * sol, int * numToSolve, char op1, char op2)
{
	size_t i,count;
	char temp[5] = "    ";

	for (i = 0; i < 32; i++)
		riddleNames[0][i] = ' ';
	riddleNames[0][i] = '\0';

	if (left == numToSolve) {
		sprintf(riddleNames[0] + i, "___");
		i += 3;
	}
	else {
		_itoa(*left, temp, 10);
		count = strlen(temp);
		sprintf(riddleNames[0] + i, temp);
		i += count;
	}

	riddleNames[0][i] = op1;
	i++;
	riddleNames[0][i] = '\0';
	if (mid == numToSolve) {
		sprintf(riddleNames[0] + i, "___");
		i += 3;
	}
	else {
		_itoa(*mid, temp, 10);
		count = strlen(temp);
		sprintf(riddleNames[0] + i, temp);
		i += count;
	}

	riddleNames[0][i] = op2;
	i++;
	riddleNames[0][i] = '\0';
	if (right == numToSolve) {
		sprintf(riddleNames[0] + i, "___");
		i += 3;
	}
	else {
		_itoa(*right, temp, 10);
		count = strlen(temp);
		sprintf(riddleNames[0] + i, temp);
		i += count;
	}
	riddleNames[0][i] = '=';
	i++;
	riddleNames[0][i] = '\0';
	if (sol == numToSolve) {
		sprintf(riddleNames[0] + i, "___");
		i += 3;
	}
	else {
		_itoa(*sol, temp, 10);
		count = strlen(temp);
		sprintf(riddleNames[0] + i, temp);
		i += count;
	}
	while (i < 79) {
		riddleNames[0][i] = ' ';
		i++;
	}
	riddleNames[0][i] = '\0';

}

#include "Riddles.h"

bool Riddles::solveRiddle(int numOfRiddle, int numToSolve)
{
	int X = riddleNames[numOfRiddle].var;
	int type = riddleNames[numOfRiddle].riddleType;

	switch (type) {
	case 0:
		return solveIsEven(numToSolve);
		break;
	case 1:
		return solveIsPrimeNumber(numToSolve);
		break;
	case 2:
		return solveNumIsDivideByX(numToSolve, X);
		break;
	case 3:
		return solveNumIsMultipleOfX(numToSolve, X);
		break;
	case 4:
		return solveNumIsPowerOfIntegerNumber(numToSolve);
		break;
	case 5:
		return collectPowOfX(numToSolve, X);
		break;
	case 6:
		return collectNumberThatCanDivideX(numToSolve, X);
		break;
	case 7:
		return (numToSolve == getExerciseSolution());
		break;
	}
	return false;
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

void Riddles::printRiddle(int currRiddle)
{
	gotoxy(1, -FIXGOTOXY + 4);
	if (riddleNames[currRiddle].riddleType == 7)
		createComplexExercise(currRiddle);
	cout << riddleNames[currRiddle].str;
}

void Riddles::createComplexExercise(int curr)
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
	createTheExcerciseString(&left, &mid, &right, &sol, numToSolve, op1, op2,curr);
}

void Riddles::countAndAllocateFromTextFile(ifstream& file)
{
	int number_of_lines=0,i=0;
	string line;

	while (!file.eof()) {//get the number of the lines
		getline(file,line);
		number_of_lines++;
	}
	numOfRiddles = number_of_lines;

	riddleNames = new singleRiddle[number_of_lines];
	file.seekg(0, ios::beg);

	while (!file.eof()) {
		getline(file, line);
		analysisRiddle(line, i);//reads the riddle and extract the type of the riddle,variable and puts it in the riddles array
		i++;
	}
	file.close();
}

void Riddles::analysisRiddle(string str, int index)
{
	string types[NUMOFRIDDLETYPES] = {
	{ "Collect Even Number" },
	{ "Collect Prime Number" },
	{ "Collect Number divided by" },
	{ "Collect Number that is multipication of" },
	{ "Collect Number that is a power of an integer number" },
	{ "Collect number that is power of" },
	{ "Collect number that can divide" },
	{ "Complex Exercise" } };
	for (int i = 0; i < NUMOFRIDDLETYPES; i++) {
		if (str.find(types[i])!=string::npos) {
			riddleNames[index].str = centerAlignTheStr(str);
			riddleNames[index].riddleType = i;
			riddleNames[index].var=extractVariableFromString(str);
		}
		
	}
}

int Riddles::extractVariableFromString(string str)
{
	int n = str.find_first_of("0123456789");
	if (n != string::npos)
	{
		std::size_t const m = str.find_first_not_of("0123456789", n);
		n = stoi(str.substr(n, m != std::string::npos ? m - n : m));
	}
	return n;
}

string Riddles::centerAlignTheStr(string str)
{
	int size=str.length();
	int n = (COLS - size)/2;//calculate the num of spaces that should be in each side
	string temp,res;

	for (int i = 0; i < n; i++)
		temp.append(" ");
	res.append(temp);
	res.append(str);
	res.append(temp);

	return res;
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

void Riddles::createTheExcerciseString(int * left, int * mid, int * right, int * sol, int * numToSolve, char op1, char op2,int curr)
{
	string res,temp;
	if (left == numToSolve)
		res.append("___");
	else 
		res.append(to_string(*left));//insert the number as a string to res

	res += op1;

	if (mid == numToSolve)
		res.append("___");
	else
		res.append(to_string(*mid));//insert the number as a string to res

	res += op2;

	if (right == numToSolve)
		res.append("___");
	else
		res.append(to_string(*right));//insert the number as a string to res

	res += '=';

	if (sol == numToSolve)
		res.append("___");
	else
		res.append(to_string(*sol));//insert the number as a string to res

	res=centerAlignTheStr(res);

	riddleNames[curr].str = res;
}

bool Riddles::solveIsEven(int numToSolve)
{
	if (numToSolve % 2 == 0)
		return true;
	else
		return false;
}

bool Riddles::solveIsPrimeNumber(int num)
{
	bool res = false;
	int prime[39] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167 };
	for (int i = 0; i < 39; i++)
		if (num == prime[i])
			return true;
	return res;
}

bool Riddles::solveNumIsDivideByX(int num, int X)
{
	if (num % X == 0)
		return true;
	return false;
}

bool Riddles::solveNumIsMultipleOfX(int num, int X)
{
	if (num % X != 0)
		return false;
	return true;
}

bool Riddles::solveNumIsPowerOfIntegerNumber(int num)
{
	bool res = false;
	for (int i = 1; i <= num; i++)
		if (i*i == num)
			return true;
	return res;
}

bool Riddles::collectPowOfX(int num, int X)
{
	for (int i = 0; i < 10; i++)
	{
		if (pow(X, i) == num)
			return true;
	}
	return false;
}

bool Riddles::collectNumberThatCanDivideX(int numToSolve, int X)
{
	for (int i = 0; i <= 169; i++)
	{
		if (numToSolve*i == X)
			return true;
	}
	return false;
}

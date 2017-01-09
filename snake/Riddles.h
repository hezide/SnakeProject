#ifndef _RIDDLES_
#define _RIDDLES_
#define _CRT_SECURE_NO_WARNINGS

#include "Point.h"
#include <string>

class Riddles {
	enum{NUM_OF_RIDDLES=10,BLOCK_X=28,BLOCK_WIDTH=26,NUMRANGE=169};
	enum {FIXGOTOXY = 5 ,COLS = 80};
	char riddleblock[6][COLS+1] = {
	//	          10        20        30        40        50        60        70       79
	//	 01234567890123456789012345678901234567890123456789012345678901234567890123456789
		"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++", // 0
		"+                                                                              +", // 1
		"+                                                                              +", // 2
		"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++", // 3
		"+                                                                              +", // 4
		"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"  // 5
	//   0123456789012345678901234567890123456789012345678901234567890123456789012345678																					//   01234567890123456789012345678901234567890123456789012345678901234567890123456789
	};
	char riddleNames[NUM_OF_RIDDLES][COLS] = {
		{"                                                                              "},
		{"                             Collect Even Number                              "},
		{"                             Collect Prime Number                             "},
		{"                          Collect Number divided by 3                         "},
		{"                   Collect Number that is multipication of 7                  "},
		{"              Collect Number that is a power of an integer number             "},
		{"                          Collect Number divided by 4                         "},
		{"                   Collect Number divided by 5 with carry 2                   "},
		{"                           Collect number that is power of 4                  "},
		{"                         Collect number that can divide 16                    "}
	};
	int exerciseSolution;
public:
	bool solveRiddle(int numOfRiddle, int numToSolve);
	void printBlock();
	void printRiddle(int currRiddle) {
		gotoxy(1, -FIXGOTOXY + 4);
		printf("%s", riddleNames[currRiddle]);
//		Sleep(500);
	}
	bool endOfRiddles(int currRiddle) {
		if (currRiddle == NUM_OF_RIDDLES)
			return true;
		else
			return false;
	}
	void createComplexExercise();
	int getExerciseSolution() {
		return exerciseSolution;
	}
private:

	int getRandomNumber(char op = ' ', int before = 0);
	char getRandOperator();
	int calcTwoNums(int num1, int num2, char op);
	bool checkIfExerciseIsLegal(const int numToSolve,int sol);
	bool divisionCase(int num1, int num2) {
		if (num2 == 0)
			return false;
		else if (num1%num2 != 0)
			return false;
		else
			return true;
	}
	int* randWhiceNumShouldBeSolved(int* left,int* mid,int* right,int* sol);
	void createTheExcerciseString(int* left, int* mid, int* right, int* sol, int* numToSolve, char op1, char op2);
	bool solveIsEven(int numToSolve) {
		if (numToSolve % 2 == 0)
			return true;
		else
			return false;
	}
	bool solveIsPrimeNumber(int num) {
		bool res = false;
		int prime[39] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167 };
		for (int i = 0; i < 39; i++)
			if (num == prime[i])
				return true;
		return res;
	}
	bool solveNumIsDivideBy3(int num) {
		if (num % 3 == 0)
			return true;
		return false;
	}
	bool solveNumIsMultipleOf7(int num) {
		if (num % 7 != 0)
			return false;
		return true;
	}
	bool solveNumIsPowerOfIntegerNumber(int num) {
		bool res = false;
		for (int i = 1; i <= num / 2; i++)
			if (i*i == num)
				return true;
		return res;
	}
	bool solveNumIsDivideBy4(int num) {
		if (num % 4 == 0)
			return true;
		return false;
	}
	bool solveNumIsDivideBy5WithCarry2(int num) {
		if (num % 5 == 2)
			return true;
		return false;
	}
	bool collectPowOf4(int num) {
		if (num == 1 || num == 4 || num == 16 || num == 64)
			return true;
		return false;
	}
	bool collectNumberThatCanDivide16(int num) {
		if (num==1 || num==2 || num==4 || num==8 || num==16)
			return true;
		return false;
	}
};

#endif

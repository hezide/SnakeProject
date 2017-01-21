#ifndef _RIDDLES_
#define _RIDDLES_
#define _CRT_SECURE_NO_WARNINGS

#include "Point.h"
#include <string>
#include <fstream>

struct singleRiddle {
	string str;
	int riddleType;
	int var;
};
class Riddles {
	enum{NUM_OF_RIDDLES=10,BLOCK_X=28,BLOCK_WIDTH=26,NUMRANGE=169,NUMOFRIDDLETYPES=8};
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
	int exerciseSolution;
	singleRiddle* riddleNames;
	int numOfRiddles;
public:
	Riddles() {
		ifstream riddlesFile( "riddlesFile.txt");
		countAndAllocateFromTextFile(riddlesFile);
	}
	bool solveRiddle(int numOfRiddle, int numToSolve);
	void printBlock();
	void printRiddle(int currRiddle);
	bool endOfRiddles(int currRiddle) {
		if (currRiddle == numOfRiddles)
			return true;
		else
			return false;
	}
	void createComplexExercise(int curr=0);
	int getExerciseSolution() {
		return exerciseSolution;
	}
	void countAndAllocateFromTextFile(ifstream& file);
	void analysisRiddle(string str, int index);
	int extractVariableFromString(string str);
	string centerAlignTheStr(string str);
	int getNumOfRiddles() {
		return numOfRiddles;
	}
	singleRiddle getRiddle(int i) {
		return riddleNames[i];
	}
	~Riddles() {
		delete []riddleNames;
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
	void createTheExcerciseString(int* left, int* mid, int* right, int* sol, int* numToSolve, char op1, char op2,int curr=0);
	
	bool solveIsEven(int numToSolve);
	bool solveIsPrimeNumber(int num);
	bool solveNumIsDivideByX(int num, int X);
	bool solveNumIsMultipleOfX(int num, int X);
	bool solveNumIsPowerOfIntegerNumber(int num);
	bool collectPowOfX(int num, int X);
	bool collectNumberThatCanDivideX(int numToSolve, int X);
};

#endif

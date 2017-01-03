#ifndef _NUMBER_H
#define _NUMBER_H

#include "Point.h"

class Number {
	Point pos[3] = { {-1,-1},{-1,-1},{-1,-1}};
	int num;
	int numOfDigits;
public:
	Point* getPos() {
		return pos;
	}
	void set3Pos(Point pointToSet,int size) {
		for (int i = 0; i < size; i++) {
			pos[i] = { pointToSet.getX() + i,pointToSet.getY() };
		}
	}
	void resetPos() {
		for (int i = 0; i < 3; i++)
			pos[i].set(-1, -1);
	}
	int getNum() {
		return num;
	}
	void setNum(int _num) {
		num = _num;
	}
	void setNumOfDigits(int _numOfDigits) {
		numOfDigits = _numOfDigits;
	}
	int getNumOfDigits() {
		return numOfDigits;
	}
	int calcNumOfDigits() {
		int tempNum = num;
		int count = 0;

		if (tempNum == 0)
			return 1;

		while (tempNum > 0) {
			tempNum /= 10;
			count++;
		}
		return count;
	}
};
#endif
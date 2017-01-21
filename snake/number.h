#ifndef _NUMBER_H
#define _NUMBER_H

#include "Point.h"

class Number {
	Point pos[3] = { {-1,-1},{-1,-1},{-1,-1}};
	int num;
	int numOfDigits;
public:
	bool operator==(Number& num1) {
		if (pos[0] == num1.getPos()[0])
			return true;
		return false;
	}
	Point* getPos() {
		return pos;
	}
	void set3Pos(Point pointToSet,int size) {
		for (int i = 0; i < size; i++) {
			pos[i] = { pointToSet.getX() + i,pointToSet.getY() };
		}
	}
	void resetPos();
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
	int calcNumOfDigits();
};
#endif
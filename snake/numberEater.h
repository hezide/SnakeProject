#ifndef _NUMBEREATER_H
#define _NUMBEREATER_H

#include "Creature.h"
#include "number.h"

class numberEater :public Creature {
	enum { ROWS = 20, COLS = 80 ,DONT_MOVE=4};
public:
	numberEater(bool isCW) {
		setCrossingWalls(isCW);
		init();
	}
	virtual void move();
	virtual void init();
	void setDirectionToNumber();
	void fixXYAxis(Point posToGo);
};

#endif

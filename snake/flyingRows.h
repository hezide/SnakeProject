#ifndef _FLYINGROWS_H
#define _FLYINGROWS_H

#include "Creature.h"

class flyingRows :public Creature {
	enum { ROWS = 20, COLS = 80 };
public: 
	flyingRows(bool isCW) {
		setCrossingWalls(isCW);
		init();
	}
	virtual void move();
	virtual void init();
	

};

#endif

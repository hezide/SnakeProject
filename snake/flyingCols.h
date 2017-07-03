#ifndef _FLYINGCOLS_H
#define _FLYINGCOLS_H

#include "Creature.h"

class flyingCols :public Creature {
	enum { ROWS = 20, COLS = 80 };

public:
	flyingCols(bool isCW) {
		setCrossingWalls(isCW);
		init();
	}
	virtual void move();
	virtual void init();


};

#endif

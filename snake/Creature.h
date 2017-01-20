#ifndef _CREATURE_H
#define _CREATURE_H

#include "Point.h"
#include "Color.h"


class TheSnakesGame;
class Creature :public Point {
	char symbol;
	int direction;
	Color color;
	bool bulletProof;
	bool crossingWalls;
	bool isActive;
	bool doubleSpeed;
	TheSnakesGame* theGame;
	
public:
	virtual void move() = 0;
	virtual void init() = 0;
	void moveAndDraw();
	void nextStepIsPossible();
	int getDirection() {
		return direction;
	}
	bool getCrossingWalls() {
		return crossingWalls;
	}
	void setDirection(int _direction){
		direction = _direction;
	}
	void setCrossingWalls(bool _set) {
		crossingWalls = _set;
	}
	void setBulletProof(bool _set) {
		bulletProof = _set;
	}
	bool getIsBulletProof() {
		return bulletProof;
	}
	void setSymbol(char ch){
		symbol = ch;
	}
	char getSymbol() {
		return symbol;
	}
	void setGame(TheSnakesGame* _theGame) {
		theGame = _theGame;
	}
	TheSnakesGame* getGame() {
		return theGame;
	}
	void setIsActive(bool val) {
		isActive = val;
	}
	bool getIsActive() {
		return isActive;
	}
		void setColor(Color _color) {
		color = _color;
	}						  
	void disappearCreature();
	bool isDoubleSpeed() {
		return doubleSpeed;
	}
	void setDoubleSpeed(bool _doubleSpeed) {
		doubleSpeed = _doubleSpeed;
	}
	void flipDoubleSpeed() {
		doubleSpeed = !doubleSpeed;
	}
};

#endif
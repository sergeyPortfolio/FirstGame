#include "MapGame.h"
#ifndef BASEWARRIOR_H
#define BASEWARRIOR_H

class BaseWarrior {
protected:
	int X;
	int Y;
	char picture;
	size_t damage;
	int health;
	int lastX;
	int lastY;

public:

	virtual void Run(MapGame &m) = 0;
	virtual void Bet(size_t h) = 0;
	virtual size_t Bump() = 0;

};


#endif
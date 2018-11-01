#include "BaseWarrior.h"
#include "MapGame.h"
#ifndef WARRIORVIKING_H
#define WARRIORVIKING_H
class WarriorViking : public BaseWarrior {

	
public:
	WarriorViking(int x, int y);
	void Run(MapGame &m);
	void Bet(size_t h);
	size_t Bump();
};
#endif
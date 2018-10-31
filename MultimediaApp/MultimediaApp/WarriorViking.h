#include "BaseWarrior.h"
#ifndef WARRIORVIKING_H
#define WARRIORVIKING_H
class WarriorViking : public BaseWarrior {

	
public:
	WarriorViking(int x, int y);
	void Run();
	void Bet(int h);
};
#endif
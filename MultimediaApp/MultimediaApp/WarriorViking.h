/*#ifndef WARRIORVIKING_H
#define WARRIORVIKING_H*/
#pragma once
#include "BaseWarrior.h"
#include "MapGame.h"

class WarriorViking : public BaseWarrior {

	
public:
	WarriorViking( MapGame &m);
	void Run(MapGame &m);
	void Bet(size_t h);
	size_t Bump();
	void  RunOrBump(MapGame &m, BaseWarrior *b, int numb);

	
};
//#endif
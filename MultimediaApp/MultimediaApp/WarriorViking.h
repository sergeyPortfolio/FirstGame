/*#ifndef WARRIORVIKING_H
#define WARRIORVIKING_H*/
#pragma once
#include "BaseWarrior.h"
#include "C_Map.h"

class WarriorViking : public BaseWarrior {

	
public:
	WarriorViking(C_Map &m);
	void Run(C_Map &m);
	void Bet(size_t h);
	size_t Bump();
	void  RunOrBump(C_Map &m, BaseWarrior *b, int numb);

	
};
//#endif
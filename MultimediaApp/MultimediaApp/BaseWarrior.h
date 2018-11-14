
/*#ifndef BASEWARRIOR_H
#define BASEWARRIOR_H*/
#pragma once
#include "C_Map.h"

class BaseWarrior {
protected:
	C_Map::position m_pos;
	char characterSymbol;
	size_t damage;
	int health;
	C_Map::position m_posLast;
	bool m_isAlive; 

public:

	virtual void Run(C_Map &m) = 0;
	virtual void Bet(size_t h) = 0;
	virtual size_t Bump() = 0;
	virtual void RunOrBump(C_Map &m, BaseWarrior *b, int numb) = 0;

};


//#endif
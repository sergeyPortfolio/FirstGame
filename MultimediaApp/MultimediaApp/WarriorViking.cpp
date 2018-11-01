#include "BaseWarrior.h"
#include "WarriorViking.h"
#include "MapGame.h"
#include <cstdlib>



	WarriorViking::WarriorViking(int x, int y) 
	{
	
		
		 X = x;
		 Y = y;
		picture = 'V';
		health = 100;

	}
	void WarriorViking :: Run(MapGame &m) 
	{
		
		int random = rand() % 3 - 0;
		switch (random)
		{
		case 0: Y++; if (m.Set(X, Y, picture) != 0) { Y--; } break;
		case 1: X++; if (m.Set(X, Y, picture) != 0) { X--; } break;
		case 2: Y--; if (m.Set(X, Y, picture) != 0) { Y++; } break;
		case 3: X--; if (m.Set(X, Y, picture) != 0) { X++; } break;
		default:
			break;
		}

		
	}
	void WarriorViking :: Bet(size_t h) 
	{
		
		health -= h;
		

	}
	size_t WarriorViking ::Bump()
	{
		damage = rand() % (25 + 15);
		return damage;
	}
	



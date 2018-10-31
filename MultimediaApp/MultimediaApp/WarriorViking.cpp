#include "BaseWarrior.h"
#include "WarriorViking.h"
#include <cstdlib>



	WarriorViking::WarriorViking(int x, int y) 
	{
	
		
		 X = x;
		 Y = y;
		picture = 'V';
		health = 100;

	}
	void WarriorViking :: Run() 
	{
		
		int random = rand() % 3 - 0;
		switch (random)
		{
		case 0: Y++; break;
		case 1: X++; break;
		case 2: Y--; break;
		case 3: X--; break;
		default:
			break;
		}

		
	}
	void WarriorViking :: Bet(int h) 
	{
		health -= h;
		if (health < 0) {
			
		}
		else damage = rand() % 25 + 15;
		

	}
	



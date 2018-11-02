#include "BaseWarrior.h"
#include "WarriorViking.h"
#include "MapGame.h"
#include <cstdlib>



	WarriorViking::WarriorViking( MapGame &m) 
	{
	
		
		
		picture = 'V';
		health = 100;

	constr:
		X = rand() % 20 + 2;
		Y = rand() % 20 + 2;
		if (m.check(X, Y) != 0 ) {
			m.Set(X, Y, picture, 1, 1);
		}
		else goto constr;

	}
	void WarriorViking :: Run(MapGame &m) 
	{
		Start:
		int random = rand() % 3 - 0;
		switch (random)
		{
			case 0: if (m.check(X, Y + 1) != 0) 
						{ lastY = Y; 
						lastX = X; 
						Y++; 
						m.Set(X, Y, picture, lastX, lastY); 
						}
					else
						goto Start;  break;
			case 1: if (m.check(X + 1, Y) != 0)  
						{ lastX = X; 
						lastY = Y; 
						X++; 
						m.Set(X, Y, picture, lastX, lastY);
						}
					else 
						goto Start;  break;
			case 2: if (m.check(X, Y - 1) != 0)
						{
						lastY = Y;
						lastX = X;
						Y--;
						m.Set(X, Y, picture, lastX, lastY);
						}
					else
						goto Start;  break;
			case 3: if (m.check(X - 1, Y) != 0)
						{
						lastX = X;
						lastY = Y;
						X--;
						m.Set(X, Y, picture, lastX, lastY);
						}
					else
						goto Start;  break;
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
	
	void WarriorViking:: RunOrBump(MapGame &m, BaseWarrior *b, int numb) {
		int choice = m.choice(X, Y);
		if (choice == 1)
		{
			for (int i = 0; i < numb; i++)
			{

				b[i].Bet(Bump());


			}
		}
		else if (choice == 0) {
			Run(m);
		}
	}


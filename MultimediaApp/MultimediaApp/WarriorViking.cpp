#include "BaseWarrior.h"
#include "WarriorViking.h"
#include "C_Map.h"
#include <cstdlib>

	
	WarriorViking::WarriorViking(C_Map &m)
	{		
		m_isAlive = true;
		characterSymbol = 'V';
		health = 100;
		bool forWhile = true;
		while (forWhile) {
			m_pos.first = rand() % 20 + 2;
			m_pos.second = rand() % 20 + 2;
			if (m.check(m_pos.first, m_pos.second) != 0)
			{
				m.Set(m_pos.first, m_pos.second, characterSymbol, 1, 1);
				forWhile = false;
			}
		}

	}
	void WarriorViking :: Run(C_Map &m)
	{
		bool forWhile = true;
		while (forWhile)
		{
			int random = rand() % 3 - 0;
			switch (random)
			{
			case 0: if (m.check(m_pos.first, m_pos.second + 1) != 0)
			{
				m_posLast.second = m_pos.second;
				m_posLast.first = m_pos.first;
				m_pos.second++;
				m.Set(m_pos.first, m_pos.second, characterSymbol, m_posLast.first, m_posLast.second);
				forWhile = false;
			} break;


			case 1: if (m.check(m_pos.first + 1, m_pos.second) != 0)
			{
				m_posLast.first  = m_pos.first;
				m_posLast.second = m_pos.second;
				m_pos.first++;
				m.Set(m_pos.first, m_pos.second, characterSymbol, m_posLast.first, m_posLast.second);
				forWhile = false;
			} break;
			case 2: if (m.check(m_pos.first, m_pos.second - 1) != 0)
			{
				m_posLast.second = m_pos.second;
				m_posLast.first = m_pos.first;
				m_pos.second--;
				m.Set(m_pos.first, m_pos.second, characterSymbol, m_posLast.first, m_posLast.second);
				forWhile = false;
			}
					break;
			case 3: if (m.check(m_pos.first - 1, m_pos.second) != 0)
			{
				m_posLast.first = m_pos.first;
				m_posLast.second = m_pos.second;
				m_pos.first--;
				m.Set(m_pos.first, m_pos.second, characterSymbol, m_posLast.first, m_posLast.second);
				forWhile = false;
			}
					break;
			default:
				break;
			}
		}

		
	}
	void WarriorViking :: Bet(size_t h) 
	{
		
		health -= h;
		if (health <= 0) {
			m_isAlive = false;
		}


	}
	size_t WarriorViking ::Bump()
	{
		damage = rand() % (25 + 15);
		return damage; 
	}
	
	void WarriorViking:: RunOrBump(C_Map &m, BaseWarrior *b, int numb) {
		int choice = m.choice(m_pos.first, m_pos.second);
		if (choice == 1)
		{
			Bet(b->Bump());
		}
		else if (choice == 0) {
			Run(m);
		}
	}


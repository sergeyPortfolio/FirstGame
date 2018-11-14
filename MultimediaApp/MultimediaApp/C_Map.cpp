#include "C_Map.h"
#include <cstdlib>
#include <iostream>

	C_Map::C_Map(int x, int y)
	{
		X_size = x;
		Y_size = y;
		decors = (X_size * Y_size) / 100 * 5;
		Map.resize(y);
		
		for (int i = 0; i < Y_size; i++) {
			Map[i].resize(X_size);

			for (int j = 0; j < X_size; j++) {
				Map[i][j] = ' ';
			}
		}

		for (int i = 0; i < Y_size; i++) {
			for (int j = 0; j < X_size; j++) {
				Map[0][j] = '-';
				Map[Y_size - 1][j] = '-';
				Map[i][0] = '|';
				Map[i][X_size - 1] = '|';
			}
		}

		for (int i = 0; i < decors; i++) {
			yCoordDecor = rand() % (Y_size - 2) + 1;
			xCoordDecor = rand() % (X_size - 2) + 1;
			Map[yCoordDecor][xCoordDecor] = '#';
		}

	}
	
	void C_Map::MapShow()
	{
		system("cls");
		for (int i = 0; i < Y_size; i++) {
			for (int j = 0; j < X_size; j++) {
				std::cout << Map[i][j];
			}
			std::cout << std::endl;
		}
	
	}
	void C_Map::Set(int x, int y, char p, int lastX, int lastY)
	{
			Map[y][x] = p;
			Map[lastY][lastX] = ' ';
	}

	bool C_Map::choice(int x, int y) {
		if ((Map[y - 1][x] == ' ' || Map[y - 1][x] == '#') && 
			(Map[y + 1][x] == ' ' || Map[y + 1][x] == '#') && 
			(Map[y][x - 1] == ' ' || Map[y][x - 1] == '#') && 
			(Map[y][x + 1] == ' ' || Map[y][x + 1] == '#'))
		{
			return 0;
		}
		else
			return 1;
	}
	
	bool C_Map:: check(int x, int y) {
		if (Map[y][x] == '#' || Map[y][x] == '|' || Map[y][x] == '-')
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}


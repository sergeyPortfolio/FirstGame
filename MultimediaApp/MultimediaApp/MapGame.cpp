#include "MapGame.h"
#include <cstdlib>
#include <iostream>

	MapGame::MapGame(int x, int y) 
	{
		X = x;
		Y = y;
		decors = (X * Y) / 100 * 5;

		Map = new char*[Y];
		for (int i = 0; i < Y; i++) {
			Map[i] = new char[X];
		}
		for (int i = 0; i < Y; i++) {
			for (int j = 0; j < X; j++) {
				Map[i][j] = ' ';
			}
		}
		for (int i = 0; i < Y; i++) {
			for (int j = 0; j < X; j++) {
				Map[0][j] = '-';
				Map[Y - 1][j] = '-';
				Map[i][0] = '|';
				Map[i][X - 1] = '|';
			}
		}
		for (int i = 0; i < decors; i++) {
			yz = rand() % (Y - 2) + 1;
			xz = rand() % (X - 2) + 1;
			Map[yz][xz] = '#';
		}

	}
	MapGame :: ~MapGame() 
	{
		for (int i = 0; i < X; i++) {
			delete[]Map[i];
		}
		delete[]Map;
	}

	void MapGame::MapShow() 
	{
		system("cls");
		for (int i = 0; i < Y; i++) {
			for (int j = 0; j < X; j++) {
				std::cout << Map[i][j];
			}
			std::cout << std::endl;
		}
	/*	for (int i = 0; i < kol; i++) {
			std::cout << w[i].Coord.health;
		}
		*/
	}
	int MapGame::Set(int x, int y, char p) 
	{
		if (Map[y][x] == ' ') 
		{
			Map[y][x] = p;
			return 0;
		}
		else if (Map[y][x] = '#')
		{
			return -1;
		}
		else
		{
			return 1;
		}
	}


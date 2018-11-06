
/*#ifndef MAPGAME_H
#define MAPGAME_H*/
#pragma once
class MapGame {
private:
	int X;
	int Y;
	char **Map;
	int decors;
	int xz;
	int yz;
public:
	MapGame(int x, int y);
	~MapGame();
	void MapShow();
	void Set(int x, int y, char p, int lastX, int lastY);
	int choice(int x, int y);
	int check(int x, int y);
};
//#endif
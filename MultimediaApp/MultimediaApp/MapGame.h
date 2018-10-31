#ifndef MAPGAME_H
#define MAPGAME_H
 


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
	void Set(int x, int y, char p);

};
#endif
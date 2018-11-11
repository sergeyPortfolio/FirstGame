

#pragma once
#include <utility>
#include <vector>
class C_Map {

private:
	size_t X_size;
	size_t Y_size;
	std::vector<std::vector<char> > Map;
	size_t decors;
	size_t xCoordDecor;
	size_t yCoordDecor;
	
public:
	typedef std::pair<size_t, size_t> position;

	C_Map(int x, int y);
	
	void MapShow();
	void Set(int x, int y, char p, int lastX, int lastY);
	bool choice(int x, int y);
	bool check(int x, int y);
};
//#endif
// MultimediaApp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

using namespace std;

struct XYcoord {
	int X;
	int Y;
	char picture;
	int damage;
	int health;
	
};

class BaseWarrior {
	
public:
	
	virtual XYcoord Run() = 0;
	virtual int Bet( int h) = 0;

};
class WarriorViking : BaseWarrior {
	
	
	
	
	
public:
	XYcoord Coord;
	WarriorViking(int x, int y) {
		Coord.X = x;
		Coord.Y = y;
		Coord.picture = 'V';
		Coord.health = 100;

	}
	XYcoord Run() {
		int random = rand() % 3 - 0;
		switch (random)
		{
		case 0: Coord.Y++; break;
		case 1: Coord.X++; break;
		case 2: Coord.Y--; break;
		case 3: Coord.X--; break;
		default:
			break;
		}
		
		return Coord;
	}
	int Bet(int h) {
		Coord.health -= h;
		if (Coord.health < 0) {
			return 2;
		}
		else Coord.damage = rand() % 25 + 15;
		return Coord.damage;
		
	}
	void RunOrBet(int x, int y, int h) {
		if (x == Coord.X+1 || x == Coord.X-1|| y == Coord.Y+1 || y == Coord.Y-1)
		{
			Bet(h);
		}
		else Run();

	}

};

class MapGame {
	int X;
	int Y;
	char **Map;
	int decors;
	int xz;
	int yz;
public:
	MapGame(int x, int y) {
		X = x;
		Y = y;
		decors = (X * Y) / 100 * 5;
		
		Map = new char*[Y];
		for(int i = 0; i < Y; i++){
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
				Map[Y-1][j] = '-';
				Map[i][0] = '|';
				Map[i][X-1] = '|';
			}
		}
		for (int i = 0; i < decors; i++) {
			yz = rand() % (Y - 2) + 1;
			xz = rand() % (X - 2) + 1;
			Map[yz][xz] = '#';
		}

	}
	~MapGame() {
		for (int i = 0; i < X; i++) {
			delete[]Map[i];
		}
		delete[]Map;
	}

 	void MapShow(WarriorViking *w, int kol) {
		system("cls");
		for (int i = 0; i < Y; i++) {
			for (int j = 0; j < X; j++) {
				cout << Map[i][j];
			}
			cout << endl;
		}
		for (int i = 0; i < kol; i++) {
			cout << w[i].Coord.health;
		}

	}
	void Get(int x, int y, char p) {
		Map[y][x] = p;
	}

};


int main()
{

	MapGame m(50,50);
	WarriorViking N1(20, 20);
	WarriorViking N2(20, 23);
	WarriorViking ob[2] = { N1, N2 };
	while (true)
	{
		N1.RunOrBet(N2.Coord.X, N2.Coord.Y, N2.Coord.damage);
		N2.RunOrBet(N1.Coord.X, N1.Coord.Y, N1.Coord.damage);
		m.Get(N2.Coord.X, N2.Coord.Y, N2.Coord.picture);
		m.Get(N2.Coord.X, N2.Coord.Y, N2.Coord.picture);
		system("pause");
		m.MapShow(ob,2);
	}
	
	
	
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

#ifndef BASEWARRIOR_H
#define BASEWARRIOR_H

class BaseWarrior {
protected:
	int X;
	int Y;
	char picture;
	int damage;
	int health;

public:

	virtual void Run() = 0;
	virtual void Bet(int h) = 0;

};


#endif
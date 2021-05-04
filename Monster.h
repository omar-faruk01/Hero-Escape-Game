#pragma once
#include "Character.h"
#include <iostream>
using namespace std;

class Monster : public Character {
	friend ostream& operator<<(ostream& osAObject, Monster mon);
public:
	void decreaseAttackPower();
	Monster(int a, int b);
	void setHP(int a);
	int getHP()const;
	void setAttackPower(int ap);
	int getAttackPower()const;
	Monster operator+(Monster m);
};
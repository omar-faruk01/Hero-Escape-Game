#pragma once
#include "Character.h"
#include "Item.h"
#include "Monster.h"

class Hero : public Character {
private:
	int defensePower;
	int retreatCount;

public:
	Item* bag[3];
	const int getDefensePower();
	void decreaseDefensePower();
	void setDefensePower(int p);
	const int getRetreatCount();
	void decreaseRetreatCount();
	const bool anyItems();
	const bool isAlive();
	int operator*(Monster& m);
	Hero(int hp, int ap, int dp, int rc);
	void setHP(int a);
	int getHP()const;
	void setAttackPower(int ap);
	int getAttackPower()const;
};

#include "hero.h"
#include "Monster.h"
#include <iostream>
#include <cassert>

const int Hero::getDefensePower() {
	return defensePower;
}

void Hero::decreaseDefensePower() {
	if (defensePower > 1)
	{
		defensePower--;
	}
}

void Hero::setDefensePower(int p)
{
	if (p >= 1)
	{
		defensePower = p;
	}
	else
	{
		defensePower = 1;
	}
}

const int Hero::getRetreatCount() {
	return retreatCount;
}

void Hero::decreaseRetreatCount() {
	if (retreatCount > 0)
	{
		retreatCount--;
	}
}

const bool Hero::anyItems() {
	for (int i = 0; i < 3; i++)
	{
		if (bag[i] != nullptr) {
			return true;
		}
	}
	return false;
}

const bool Hero::isAlive() {
	if (this->hp > 0) {
		return true;
	}
	return false;
}

int Hero::operator*(Monster& m)
{
	m.setHP(m.getHP() - this->getAttackPower() < 0 ? 0 : m.getHP() - this->getAttackPower());
	this->setHP(this->getHP() - m.getAttackPower() / this->getDefensePower());

	m.decreaseAttackPower();
	this->decreaseDefensePower();

	if (this->isAlive() == false) // hero died
		return -1;
	else if (m.getHP() <= 0) // monster died
		return 1;
	else   // no character died
		return 0;
}

void Hero::setHP(int a)
{
	if (a > 1)
	{
		hp = a;
	}
	else
		hp = 0;
}

int Hero::getHP() const
{
	return hp;
}

void Hero::setAttackPower(int ap)
{
	if (ap > 1)
	{
		attackPower = ap;
	}
	else
		attackPower = 1;
}

int Hero::getAttackPower() const
{
	return attackPower;
}

Hero::Hero(int hp, int ap, int dp, int rc) {
	setHP(hp);
	setAttackPower(ap);
	setDefensePower(dp);
	if (rc >= 0)
	{
		retreatCount = rc;
	}
	else
	{
		retreatCount = 0;
	}
	bag[0] = nullptr;
	bag[1] = nullptr;
	bag[2] = nullptr;
}
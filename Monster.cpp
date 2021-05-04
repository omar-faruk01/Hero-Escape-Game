#include "Monster.h"
#include "Character.h"
#include "Hero.h"

void Monster::decreaseAttackPower() {
	if (attackPower > 1)
	{
		attackPower--;
	}
}

Monster::Monster(int a, int b)
{
	setHP(a);
	setAttackPower(b);
}

void Monster::setHP(int a)
{
	if (a > 1)
	{
		hp = a;
	}
	else
	{
		hp = 0;
	}
}

int Monster::getHP() const
{
	return hp;
}

void Monster::setAttackPower(int ap)
{
	if (ap > 1)
	{
		attackPower = ap;
	}
	else
	{
		attackPower = 1;
	}
}

int Monster::getAttackPower() const
{
	return attackPower;
}

Monster Monster::operator+(Monster m)
{
	Monster* temp = new Monster(1, 1);
	temp->setHP(this->getHP() + m.getHP());
	temp->setAttackPower(this->getAttackPower() + m.getAttackPower());
	return *temp;
}

ostream& operator<<(ostream& osAObject, Monster mon)
{
	osAObject << "HP: " << mon.getHP()
		<< "Attackpower: " << mon.getAttackPower();

	return osAObject;
}
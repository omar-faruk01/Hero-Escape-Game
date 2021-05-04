#pragma once
class Character {
protected:
	int hp;
	int attackPower;

public:
	virtual void setHP(int temp) = 0;
	virtual int getHP() const = 0;
	virtual void setAttackPower(int temp) = 0;
	virtual int getAttackPower() const = 0;
};
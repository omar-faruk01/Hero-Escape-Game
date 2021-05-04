#pragma once

class Item {
private:
	int type;
	int value;

public:
	const bool isHP();
	const bool isDefense();
	const int getValue();
	Item(int a, int b);
};

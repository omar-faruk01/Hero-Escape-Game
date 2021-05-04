#include "item.h"

const bool Item::isHP() {
	if (type == 0) {
		return true;
	}
	return false;
}

const bool Item::isDefense() {
	if (type == 1) {
		return true;
	}
	return false;
}

const int Item::getValue() {
	return value;
}

Item::Item(int a, int b) {
	type = a;
	value = b;
}
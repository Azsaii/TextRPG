#include <iostream>
#include "MonsterOrc.h"

MonsterOrc::MonsterOrc() {
	_hp = 80;
	_attackPower = 35;
	_defence = 30;
	_name = "Orc";
	_expReward = 100;

	_dropItem._name = "Orc Leather";
	_dropItem._price = 100;
}

void MonsterOrc::MonsterAttackProc(void) {
	std::cout << "* " << _name << "is attacking!\n";
}
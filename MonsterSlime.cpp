#include <iostream>
#include "MonsterSlime.h"

MonsterSlime::MonsterSlime() {
	_hp = 30;
	_attackPower = 215;
	_defence = 10;
	_name = "Slime";
	_expReward = 50;

	_dropItem._name = "Slime Jelly";
	_dropItem._price = 30;
}

void MonsterSlime::MonsterAttackProc(void) {
	std::cout << "* " << _name << "is attacking!\n";
}
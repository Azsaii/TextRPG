#include <iostream>
#include "MonsterGoblin.h"

MonsterGoblin::MonsterGoblin() {
	_hp = 50;
	_attackPower = 25;
	_defence = 20;
	_name = "Goblin";
	_expReward = 70;

	_dropItem._name = "Goblin Ear";
	_dropItem._price = 60;
}

void MonsterGoblin::MonsterAttackProc(void) {
	std::cout << "* " << _name << "is attacking!\n";
}
#include "DungeonFloor1.h"
#include "MonsterSlime.h"
#include "MonsterGoblin.h"
#include "MonsterOrc.h"

DungeonFloor1::DungeonFloor1() {

	normalMonsterCnt = 3;
	_dungeonName = "Floor 1";
	_monsters.push_back(new MonsterSlime);
	_monsters.push_back(new MonsterGoblin);
	_monsters.push_back(new MonsterOrc);

	_clearCheck.resize(3);
}

DungeonFloor1::~DungeonFloor1() {
	for (Monster* m : _monsters) {
		if (m != nullptr) delete m;
	}
}
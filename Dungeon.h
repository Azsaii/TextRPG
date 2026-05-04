#pragma once
#include <vector>
#include <string>
#include "Monster.h"

class Dungeon {
public:
	__int32 normalMonsterCnt;
	std::string _dungeonName;
	std::vector<Monster*> _monsters;
	std::vector<bool> _clearCheck;
};
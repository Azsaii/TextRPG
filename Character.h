#pragma once
#include <string>

struct Item {
	unsigned __int32 _price;
	std::string _name;
	void PrintInfo(void) const;
};

class Character {
public:
	unsigned __int32 _hp;
	unsigned __int32 _mp;
	unsigned __int32 _attackPower;
	unsigned __int32 _defence;
	unsigned __int32 _level;

	std::string _name;
};
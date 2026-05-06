#pragma once
#include <unordered_map>
#include "Job.h"

class Player: public Character {

private:
	unsigned __int32 _statLimit = 1000;
	
public:
	Player();
	~Player();

	unsigned __int32 _exp;
	unsigned __int32 _maxExp;

	unsigned __int32 _LevelUpHpAdd;
	unsigned __int32 _LevelUpMpAdd;
	unsigned __int32 _LevelUpAttackPowerAdd;
	unsigned __int32 _LevelUpDefenceAdd;

	unsigned __int32 _inventory_limit;

	Job* _job;
	std::unordered_map<ItemName, __int32> _inventory;

	void CreateCharacter(void);
	void PrintStatus(void) const;
	void StatusUpgrade(void);
	void JobSelection(void);
	void PrintInventoryInfo(void) const;
	bool AddExp(unsigned __int32);

	ItemName GetItemNameByIndex(unsigned __int32);
	void UseItem(ItemName itemName);
};
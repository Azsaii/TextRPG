#pragma once
#include "Player.h"
#include "Dungeon.h"
#include "PotionShop.h"

class GameManager {
private:
	static GameManager* _instance;
	Player _player;
	PotionShop _potionShop;
	GameManager();
public:
	
	GameManager(const GameManager&) = delete;
	GameManager& operator=(const GameManager&) = delete;
	~GameManager() = default;

	Dungeon* _currentDungeon;

	static GameManager* GetInstance(void);
	void StartPlayerSetting(void);
	void MainMenuProc(void);
	void StartBattle(Dungeon* dungeon);
};
#include <iostream>
#include "GameManager.h"
#include "DungeonFloor1.h"

using namespace std;

GameManager::GameManager(void) {
	_currentDungeon = nullptr;


}

GameManager* GameManager::GetInstance(void) {
	if (_instance == nullptr) {
		_instance = new GameManager();
	}
	return _instance;
}

void GameManager::StartPlayerSetting(void) {
	_player.CreateCharacter();
	_player.PrintStatus();
	_player.StatusUpgrade();
	_player.JobSelection();
}

void GameManager::MainMenuProc(void) {
	cout << "\n\n";

	bool ch = true;
	__int32 ans;

	while (ch) {

		cout << "\n=== Main Menu ===\n";
		cout << "1. Enter Dungeon\n";
		cout << "2. Check Inventory\n";
		cout << "3. Potion Shop\n";
		cout << "0. Quit\n";

		cout << "\nChoose: ";
		cin >> ans;

		switch (ans) {
		case 0: {
			cout << "Good Bye.";
			ch = false;
			break;
		}
		case 1: {
			Dungeon* currentDungeon = new DungeonFloor1;
			StartBattle(currentDungeon);
			delete currentDungeon;
			break;
		}
		case 2: {
			_player.PrintInventoryInfo();
			break;
		}
		case 3: {
			_potionShop.ShowPotionShopMenu();
			break;
		}
		default: {
			cout << "Invalid input.\n";
			ch = true;
			break;
		}
		}
	}
}

void GameManager::StartBattle(Dungeon* dungeon) {

	cout << "\n\n";

	__int32 currentRoomIndex = 0;
	for (; currentRoomIndex < dungeon->normalMonsterCnt; currentRoomIndex++) {
		if (dungeon->_clearCheck[currentRoomIndex] == false) break;
	}

	Monster* targetMonster = dungeon->_monsters[currentRoomIndex];

	cout << "< " << dungeon->_dungeonName << " >\n";
	cout << "[ Battle Start! ] " << _player._name << " vs " << targetMonster->_name << "\n\n";


	bool isPlayerTurn = true;
	bool isBattleNotEnd = true;
	while (isBattleNotEnd) {

		if (isPlayerTurn == true) {
			cout << "--- Player Turn ---\n";
			bool ch = true;
			while (ch) {
				ch = false;
				cout << "1. Attack\n";
				cout << "2. Use Item\n";
				cout << "Choose: ";
				__int32 ans;
				cin >> ans;
				switch (ans) {
				case 1: {
					_player._job->JobAttackProc(_player._attackPower, targetMonster);
					if (targetMonster->_hp == 0) {
						cout << " (Dead)\n";
						isBattleNotEnd = false;		

						cout << "¡Ú Victory!\n";

						cout << "  -> Got: " << targetMonster->_dropItem._name<< "!\n";
						cout << "Save to inventory.\n";
						_player._inventory.push_back(targetMonster->_dropItem);

						cout << "  -> +" << targetMonster->_expReward << " EXP! (EXP: ";
						cout << _player._exp + targetMonster->_expReward << "/" << _player._maxExp << ")\n\n";

						if (_player.AddExp(targetMonster->_expReward) == true) {
							cout << "... Level up condition met\n";
							cout << "  -> Level Up! Lv." << _player._level - 1 << " -> Lv." << _player._level << '\n';
							cout << "  -> HP +" << _player._LevelUpHpAdd << ", MP +" << _player._LevelUpMpAdd;
							cout << ", Attack +" << _player._LevelUpAttackPowerAdd << ", Defence +" << _player._LevelUpDefenceAdd;
						}
					}
					break;
				}
				case 2: {

					break;
				}
				default: {
					cout << "Invalid input.\n";
					ch = true;
					break;
				}
				}
			}
		}
		else {

		}
	}

	cout << "\n\n";
}

GameManager* GameManager::_instance;
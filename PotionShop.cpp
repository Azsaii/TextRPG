#include <iostream>
#include "PotionShop.h"

using namespace std;

void Recipe::PrintPotionInfo(void) const {

	cout << "-> " << Item::GetItemName(_potionName) << " (";

	bool isFirst = true;
	for (const auto& [key, val] : _ingredients) {
		if (!isFirst) cout << ", ";
		cout << Item::GetIngredientName(key) << " x" << val;
		isFirst = false;
	}

	cout << ")\n";
}

PotionShop::PotionShop() {

	Recipe HPPotion;
	HPPotion._potionName = HP_POTION;
	HPPotion._ingredients[HERB] = 1;
	HPPotion._ingredients[CLEAR_WATER] = 1;
	_recipes.push_back(HPPotion);

	Recipe MPPotion;
	MPPotion._potionName = MP_POTION;
	MPPotion._ingredients[HERB] = 2;
	MPPotion._ingredients[CLEAR_WATER] = 1;
	_recipes.push_back(MPPotion);

	Recipe StaminaPotion;
	StaminaPotion._potionName = STAMINA_POTION;
	StaminaPotion._ingredients[HERB] = 1;
	StaminaPotion._ingredients[BERRY] = 1;
	_recipes.push_back(StaminaPotion);

}

void PotionShop::ShowPotionShopMenu(void) const {

	cout << "\n\n";

	bool loop = true;
	__int32 in;
	string search;

	while (loop) {

		cout << "=== Potion Shop ===\n";
		cout << "1. Show all recipes\n";
		cout << "2. Search by potion name\n";
		cout << "3. Search by ingredient\n";
		cout << "0. Go back\n";

		cout << "\nChoose: ";
		if (!(cin >> in)) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Invalid input.\n";
			continue;
		}

		switch (in) {
		case 0: {
			cout << "Good Bye.\n";
			loop = false;
			break;
		}
		case 1: {
			PrintAllRecipes();
			break;
		}
		case 2: {	
			cout << "Search potion name: ";
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			getline(cin, search);
			SearchByPotionName(search);
			break;
		}
		case 3: {
			cout << "Search ingredient: ";
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			getline(cin, search);
			SearchByIngredient(search);
			break;
		}
		default: {
			cout << "Invalid input.\n";
			break;
		}
		}
	}
}

void PotionShop::PrintAllRecipes(void) const {

	cout << "\n\n";
	cout << "< All recipes >\n";

	for (const auto& recipe : _recipes) {
		recipe.PrintPotionInfo();
	}

	cout << "\n\n";
}

void PotionShop::SearchByPotionName(string potionName) const {

	bool check = false;
	for (const auto& recipe : _recipes) {
		if (Item::GetItemName(recipe._potionName) == potionName) {
			recipe.PrintPotionInfo();
			check = true;
			break;
		}
	}
	if (check == false) cout << "Potion not found.\n";

	cout << "\n\n";
}

void PotionShop::SearchByIngredient(string ingredientName) const {

	__int32 cnt = 0;
	for (const auto& recipe : _recipes) {	
		for (const auto& [key, val] : recipe._ingredients) {
			if (Item::GetIngredientName(key) == ingredientName) {
				recipe.PrintPotionInfo();
				cnt++;
			}
		}
	}

	cout << "Found " << cnt << " recipes.\n";
	cout << "\n\n";
}
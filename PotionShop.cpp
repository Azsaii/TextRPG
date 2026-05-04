#include <iostream>
#include "PotionShop.h"

using namespace std;

string Recipe::GetPotionName(void) const {

	switch (_potionName) {
	case HP_POTION: return "HPPotion";
	case STAMINA_POTION: return "StaminaPotion";
	}

	return "InvalidPotionName";
}

string Recipe::GetIngredientName(IngredientName name) const {

	switch (name) {
	case HERB: return "Herb";
	case CLEAR_WATER: return "Clear Water";
	case BERRY: return "Berry";
	}

	return "InvalidIngredientName";
}

void Recipe::PrintPotionInfo(void) const {

	cout << "-> " << GetPotionName() << " (";

	bool isFirst = true;
	for (const auto& [key, val] : _ingredients) {
		if (!isFirst) cout << ", ";
		cout << GetIngredientName(key) << " x" << val;
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

	Recipe StaminaPotion;
	StaminaPotion._potionName = STAMINA_POTION;
	StaminaPotion._ingredients[HERB] = 1;
	StaminaPotion._ingredients[BERRY] = 1;
	_recipes.push_back(StaminaPotion);

}

void PotionShop::ShowPotionShopMenu(void) const {

	cout << "\n\n";

	bool ch = true;
	__int32 ans;
	string in;

	while (ch) {

		cout << "=== Potion Shop ===\n";
		cout << "1. Show all recipes\n";
		cout << "2. Search by potion name\n";
		cout << "3. Search by ingredient\n";
		cout << "0. Go back\n";

		cout << "\nChoose: ";
		cin >> ans;

		switch (ans) {
		case 0: {
			cout << "Good Bye.\n";
			ch = false;
			break;
		}
		case 1: {
			PrintAllRecipes();
			break;
		}
		case 2: {	
			cout << "Search potion name: ";
			cin >> in;
			SearchByPotionName(in);
			break;
		}
		case 3: {
			cout << "Search ingredient: ";
			cin >> in;
			SearchByIngredient(in);
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
		if (recipe.GetPotionName() == potionName) {
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
			if (recipe.GetIngredientName(key) == ingredientName) {
				recipe.PrintPotionInfo();
				cnt++;
			}
		}
	}

	cout << "Found " << cnt << " recipes.\n";
	cout << "\n\n";
}
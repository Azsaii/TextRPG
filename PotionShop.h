#pragma once
#include <string>
#include <vector>
#include <unordered_map>

enum PotionName {
	HP_POTION,
	STAMINA_POTION,
};

enum IngredientName {
	HERB,
	CLEAR_WATER,
	BERRY
};

struct Recipe {
	PotionName _potionName;
	std::unordered_map<IngredientName, __int32> _ingredients;

	std::string GetPotionName(void) const;
	std::string GetIngredientName(IngredientName name) const;
	void PrintPotionInfo(void) const;
};

class PotionShop {
private:
	std::vector<Recipe> _recipes;
public:
	PotionShop();
	void ShowPotionShopMenu(void) const;
	void PrintAllRecipes(void) const;
	void SearchByPotionName(std::string potionName) const;
	void SearchByIngredient(std::string ingredientName) const;
};
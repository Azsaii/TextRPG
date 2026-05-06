#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "ItemDefine.h"

struct Recipe {
	ItemName _potionName;
	std::unordered_map<IngredientName, __int32> _ingredients;
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
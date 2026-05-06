#pragma once
#include <string>

enum ItemName {
	HP_POTION,
	MP_POTION,
	STAMINA_POTION,
	POTION_END,

	SLIME_JELLY,
	GOBLIN_EAR,
	ORC_LEATHER,
	DRAGON_HEART,
	ITEM_END,
	INVALID,
};

enum IngredientName {
	HERB,
	CLEAR_WATER,
	BERRY
};

class Item {
public:
	static std::string GetItemName(ItemName name);
	static __int32 GetItemPrice(ItemName name);
	static std::string GetIngredientName(IngredientName name);
};
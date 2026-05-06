
#include "ItemDefine.h"

using namespace std;

string Item::GetItemName(ItemName name) {

	switch (name) {
	case HP_POTION: return "HP Potion";
	case MP_POTION: return "MP Potion";
	case STAMINA_POTION: return "Stamina Potion";

	case SLIME_JELLY: return "Slime Jelly";
	case GOBLIN_EAR: return "Goblin Ear";
	case ORC_LEATHER: return "Orc Leather";
	case DRAGON_HEART: return "Dragon Heart";
	}

	return "InvalidItemName";
}

__int32 Item::GetItemPrice(ItemName name) {

	switch (name) {
	case HP_POTION: return 50;
	case MP_POTION: return 50;
	case STAMINA_POTION: return 60;

	case SLIME_JELLY: return 30;
	case GOBLIN_EAR: return 50;
	case ORC_LEATHER: return 70;
	case DRAGON_HEART: return 200;
	}

	return 0;
}

string Item::GetIngredientName(IngredientName name) {

	switch (name) {
	case HERB: return "Herb";
	case CLEAR_WATER: return "Clear Water";
	case BERRY: return "Berry";
	}

	return "InvalidIngredientName";
}
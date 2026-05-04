#include <iostream>
#include "Character.h"

void Item::PrintInfo(void)const {
	std::cout << _name << " (" << _price << "G)\n";
}
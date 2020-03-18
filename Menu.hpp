#include "FoodItem.hpp"
#include <vector>
#include <string>

#ifndef MENU_HPP
#define MENU_HPP

class Menu{
public:
	std::vector<FoodItem*> foodMenu;

	void addToMenu(std::string inName, int inQuant, double inPrice){
		FoodItem *temp = new FoodItem(inName, inQuant, inPrice);
		foodMenu.push_back(temp);
	}


};

#endif
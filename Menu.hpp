
#ifndef MENU_HPP
#define MENU_HPP

#include "FoodItem.hpp"
#include <iomanip>
#include <vector>
#include <string>


class Menu{
public:
	std::vector<FoodItem*> foodMenu;

	void addToMenu(std::string inName, int inQuant, double inPrice){
		FoodItem *temp = new FoodItem(inName, inPrice, inQuant);
		foodMenu.push_back(temp);
	}

	void displayMenu(){
		std::cout << std::setprecision(2) << std::fixed;
		for (int i = 0; i < foodMenu.size(); i++){
			std::cout << i <<".  ID: " << foodMenu[i]->selfID << " | Name: " << foodMenu[i]->itemName << " | Price: " << foodMenu[i]->itemPrice << " | Quantity: " << foodMenu[i]->itemQuantity << std::endl;
		}
	}


};

#endif
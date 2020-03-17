#ifndef FOODITEM_HPP
#define FOODITEM_HPP

#include <iostream>
#include <string>

class FoodItem{
public:
	static int foodID;
	std::string itemName;
	double itemPrice;
	int itemQuantity;

	FoodItem(std::string inName, double inPrice, int inQuant){
		int selfID = foodID++;
		itemName = inName;
		itemPrice = inPrice;
		itemQuantity = inQuant;
	}

	~FoodItem(){
		std::cout << "FoodItem successfully destroyed" << std::endl;
	}
};

int FoodItem::foodID = 0;

#endif
#ifndef FOODITEM_HPP
#define FOODITEM_HPP

#include <iostream>
#include <string>

class FoodItem{
public:
	static int foodID;
	int selfID;
	std::string itemName;
	double itemPrice;
	int itemQuantity;
	double priceForItems;

	FoodItem(std::string inName, double inPrice, int inQuant){
		selfID = foodID++;
		itemName = inName;
		itemPrice = inPrice;
		itemQuantity = inQuant;
	}

	FoodItem(std::string inName, double inPrice, int inQuant, double inPriceForItems){
		itemName = inName;
		itemPrice = inPrice;
		itemQuantity = inQuant;
		priceForItems = inPriceForItems;
	}

	~FoodItem(){
		std::cout << "FoodItem successfully destroyed" << std::endl;
	}
};

int FoodItem::foodID = 0;

#endif
#ifndef ORDER_HPP
#define ORDER_HPP

#include "FoodItem.hpp"
#include "Menu.hpp"
#include <ctime>
#include <string>
#include <vector>

class Order{
public:
	std::vector<FoodItem*> receipt;
	std::string orderTime;
	int totalOrderCost;
	
	void viewOrder(){
		
		double totalOrderCost = 0;
		if (receipt.size() == 0){
			std::cout << "No order placed\n";
		}
		else{
			std::cout << "__________________________RECEIPT______________________" << std::endl;
			for (int i = 0; i < receipt.size();i++){
				receipt[i]->priceForItems = (receipt[i]->itemPrice) * (double)(receipt[i]->itemQuantity);
				totalOrderCost += receipt[i]->priceForItems;
				
				std::cout << i <<". " << receipt[i]->itemName << " | Price: "; 
				std::cout << std::fixed;
				std::cout << std::setprecision(2) << receipt[i]->itemPrice << " | Amount: " << receipt[i]->itemQuantity << " | Total: "; 
				std::cout << std::setprecision(2) << receipt[i]->priceForItems << std::endl;
				
			}
			std::cout << "______________________Total: MYR" << std::setprecision(2) << totalOrderCost << "___________________" << std::endl;
		}
	}

	void addToOrder(Menu *inMenu){
		int sel = 0;
		std::string foodName;
		int quant = 0;
		double price = 0;
		double itemPrices = 0;

	
		std::cout << "Select food item: ";
		std::cin >> sel;
		foodName = inMenu->foodMenu[sel]->itemName;
		std::cout << foodName << " selected.\n";

		std::cout << "Please enter quantity: ";
		std::cin >> quant;
		inMenu->foodMenu[sel]->itemQuantity -= quant;

		itemPrices = (inMenu->foodMenu[sel]->itemPrice) * quant;

		FoodItem *temp = new FoodItem(foodName,inMenu->foodMenu[sel]->itemPrice,quant,itemPrices);
		receipt.push_back(temp);
	}

	void removeFromOrder(){
		//display order
		for (int i = 0; i < receipt.size(); i++){
			std::cout << i+1 << ". " << receipt[i]->itemName << " | " << receipt[i]->itemQuantity << std:: endl;
		}

		std::cout << "Select which item to remove: ";

		int sel = 0;

		std::cin >> sel;

		delete receipt[sel];
		receipt.erase(receipt.begin() + sel); 

	}

	Order(){
		time_t now = time(0);
		orderTime =  ctime(&now);
	}
	~Order(){

	}
	
};
#endif
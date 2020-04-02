#ifndef ORDER_HPP
#define ORDER_HPP

#include "FoodItem.hpp"
#include "Menu.hpp"
#include <ctime>
#include <string>
#include <vector>
#include <iomanip>

class Order{
public:
	std::vector<FoodItem*> receipt;
	std::string orderTime;
	double totalOrderCost;
	
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
		//inMenu->foodMenu[sel]->itemQuantity -= quant;

		itemPrices = (inMenu->foodMenu[sel]->itemPrice) * quant;
		totalOrderCost += itemPrices;
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

		totalOrderCost -= receipt[sel - 1]->itemQuantity * receipt[sel - 1]->itemPrice;
		delete receipt[sel - 1];
		receipt.erase(receipt.begin() + (sel -1));

		 

	}

	void checkOut(Menu *inMenu){
		double inPaid = 0;
		double input = 0;
		
		std::cout << "Total: RM" << std::setprecision(2) << totalOrderCost << std::endl;
		while (inPaid < totalOrderCost){
			
			std::cout << "Please enter cash: ";
			std::cin >> input;
			inPaid += input;
			std::cout << "Total paid : RM" << std::setprecision(2) << inPaid << std::endl;
			std::cout << "Remaining cost: RM" << std::setprecision(2) << totalOrderCost - inPaid << std::endl;	
		}
		for (int i = 0; i < receipt.size(); i++){
			for (int j = 0; j < inMenu->foodMenu.size();j++){
				if (receipt[i]->itemName == inMenu->foodMenu[j]->itemName){
					inMenu->foodMenu[j]->itemQuantity -= receipt[i]->itemQuantity;
				}
			}
		}
		std::cout << "Payment completed! Thank you!\n";
	}

	Order(){
		time_t now = time(0);
		orderTime =  ctime(&now);
	}
	~Order(){

	}
	
};
#endif
#ifndef MENU_HPP
#define MENU_HPP

#include "FoodItem.hpp"
//#include "Order.hpp"
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
		std::cout << "======================== MENU ========================\n";
		for (int i = 0; i < foodMenu.size(); i++){
			std::cout << i <<".  ID: " << foodMenu[i]->selfID << " | Name: " << foodMenu[i]->itemName << " | Price: " << foodMenu[i]->itemPrice << " | Quantity: " << foodMenu[i]->itemQuantity << std::endl;
		}
		std::cout << "======================================================\n";

	}

	void deleteItem(int selection){
		delete foodMenu[selection];
		foodMenu.erase(foodMenu.begin() + selection);
	}
/*
	void viewTransactionHistory(std::vector<Order*> inTransHistory){
		int sel = 0;
		while (sel != -1){
			for (int i = 0; i < inTransHistory.size(); i++){
				std::cout << i << ". " << inTransHistory[i]->orderTime << "\n";
			}

			std::cout << "Please select which transaction to view or enter -1 to exit: ";
			std::cin >> sel;

			if (sel >= 0 && sel < inTransHistory.size()){
				inTransHistory[sel]->viewOrder();
			}
			else if ( sel == -1){
				return;
			}
			else{
				std::cout << "Please select within the range or enter -1 to exit";
			}
		}
	}
	*/

	Menu(){

	}

	~Menu(){
		
	}

};

#endif
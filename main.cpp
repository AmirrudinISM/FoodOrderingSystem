#include "Menu.hpp"
#include "FoodItem.hpp"
#include "Order.hpp"
#include "Transaction.hpp"
#include <iomanip>
#include <iostream>

bool adminLogin();
void customerMenu(Menu *in, Transaction *inHistory);
void adminMenu(Menu *in2);


int main(){
	/*
	Menu test;
	test.addToMenu("Chicken",10,5.5);
	test.addToMenu("Burger",33,2.5);
	test.addToMenu("Fries",29,2.0);
	test.addToMenu("Soda",50,1.5);
	test.displayMenu();
	*/
	
	Menu *A = new Menu();
	A->addToMenu("Burger", 80, 4.5);
	A->addToMenu("Fries", 80, 2.5);
	A->addToMenu("Soda",50,1.5);
	A->addToMenu("Chicken",10,6.8);

	Transaction *transHistory = new Transaction();

	std::cout <<"FOOD ORDERING SYSTEM DEMO" << std::endl;

	int comInput = 0;
	bool authenticStat = false;

	while (comInput != 9){
		//prompt & get command input
		std::cout << "1. ADMIN" << std::endl;
		std::cout << "2. CUSTOMER" << std::endl;
		std::cout << "9. Exit program" << std::endl;
		std::cout << "Select profile to login: ";

		std::cin >> comInput;


		switch(comInput){
			//user need to authenticate themselves to use admin menu
			case 1:
				//authenticStat = adminLogin();
				//if (authenticStat == true){
					adminMenu(A);
				//}
				break;

			//customer; no need for authentication
			case 2:
				customerMenu(A, transHistory);
				break;

			case 9:
				std::cout << "Thank you!\nExiting system...\n"; 
				break;

			default:
				std::cout << "Please enter the displayed number" <<std::endl;
				break;
		}
	}
	
	return 0;
}

//Admin menu: 
//1. view menu
//2. Manage menu(add food item to menu, delete menu items) 
//3. view tramsaction history
bool adminLogin(){
	std::cout << "Logging in as Admin..." <<std::endl;

	//data
	std::string userName = "SysAdmin";
	std::string sysPassword = "Unikl2020";
	//input
	std::string inUName = "";
	std::string inPassword = "";

	//prompt & get username & password
	std::cout << "Enter username: ";
	std::cin >> inUName;

	if (inUName == userName){
		std::cout << "Enter password: ";
		std::cin >> inPassword;
		if (inPassword == sysPassword){
			std::cout << "Login successfull!\n Welcome, SysAdmin!\n";
			return true;
		}
		else{
			std::cout << "Incorrect password\n";
			return false;
		}

	}
	else{
		std::cout << "User does not exist" << std::endl;
		return false;
	}

	return false;
}


//Customer menu:
//1. view Order, 
//2. Manage order(add to order, remove from order), 
//3. apply discount
//4. make payment
void customerMenu(Menu *in, Transaction *inHistory){
	Order *currentOrder = new Order();
	int custIn = 0;

	while(custIn != 9){
		//prompt & get input
		std::cout << "1. View Order\n";
		std::cout << "2. Add to order\n";
		std::cout << "3. Remove from order\n";
		std::cout << "4. Checkout\n";
		std::cout << "9. Exit\n";
		std::cout << "Select action: ";
		
		std::cin >> custIn;
		switch(custIn){
			case 1:
				currentOrder->viewOrder();
				break;
			case 2:
				in->displayMenu();
				currentOrder->addToOrder(in);
				break;
			case 3:
			case 4:
			case 9:
			default:
				std::cout << "Please enter correct value.\n"; 
				break;
		}
	}
}

void adminMenu(Menu *in2){
	
	int adminIN = 0;
	int menuSelect = 0;
	while (adminIN != 9){
		//prompt & get input
		std::cout << "1. View menu\n";
		std::cout << "2. Add to menu\n";
		std::cout << "3. Remove from menu\n";
		std::cout << "9. Exit\n";
		std::cout << "Select action: ";

		std::string inName;
		int inQuant;
		double inPrice;
	

		std::cin >> adminIN;

		switch(adminIN){
			//view menu
			case 1:
				std::cout << "Viewing menu\n";
				in2->displayMenu();
				break;
			//manage menu
			case 2:
				std::cout << "Managing menu\n";
				
				std::cout << "Please enter food name: ";
				std::cin >> inName;

				std::cout << "Please enter food quantity: ";
				std::cin >> inQuant;

				std::cout << "Please enter food price: ";
				std::cin >> inPrice;

				in2->addToMenu(inName, inQuant, inPrice);
				break;
			//view transaction history
			case 3:
				std::cout << "Removing from menu\n";
				in2->displayMenu();

				std::cout << "Select the item to remove: ";
				std::cin >> menuSelect;

				in2->deleteItem(menuSelect);
				break;
			case 9:
				std::cout << "Logging out from Admin menu...\n"; 
				break;
			default:
				std::cout << "Please enter correct value.\n"; 
				break;
		}
	}	
	
	
}

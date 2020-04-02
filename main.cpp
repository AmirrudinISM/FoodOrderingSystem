#include "Menu.hpp"
#include "FoodItem.hpp"
#include "Order.hpp"
#include <iomanip>
#include <iostream>

bool adminLogin();
std::vector<Order*> customerMenu(Menu *in, std::vector<Order*> inTransHist);
void adminMenu(Menu *in2, std::vector<Order*> inTransHist);


int main(){

	Menu *A = new Menu();
	A->addToMenu("Burger", 80, 4.5);
	A->addToMenu("Fries", 80, 2.5);
	A->addToMenu("Soda",50,1.5);
	A->addToMenu("Chicken",10,6.8);

	//keeps records of orders
	std::vector<Order*> transactionHistory; 

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
					adminMenu(A, transactionHistory);
				//}
				break;

			//customer; no need for authentication
			case 2:
				transactionHistory = customerMenu(A, transactionHistory);
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
std::vector<Order*> customerMenu(Menu *in, std::vector<Order*> inTransHist){
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
				//remove order
				currentOrder->removeFromOrder();
				break;
			case 4:
				currentOrder->checkOut();
				inTransHist.push_back(currentOrder);
				return inTransHist;
				goto EXIT;
				break;
			case 9:
				std::cout << "Logging out...\n";
				break;
			default:
				std::cout << "Please enter correct value.\n"; 
				break;
		}
		
	}
	EXIT: std::cout << "Thank you!\n";
}

void adminMenu(Menu *in2, std::vector<Order*> inTransHist){
	
	int adminIN = 0;
	int menuSelect = 0;
	
	while (adminIN != 9){
		int sel = 0;
		//prompt & get input
		std::cout << "1. View menu\n";
		std::cout << "2. Add to menu\n";
		std::cout << "3. Remove from menu\n";
		std::cout << "4. View transaction history\n";
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
			//delete menu item
			case 3:
				std::cout << "Removing from menu\n";
				in2->displayMenu();

				std::cout << "Select the item to remove: ";
				std::cin >> menuSelect;

				in2->deleteItem(menuSelect);
				break;
			case 4:
				
				while (sel != -1){
					//std::cout <<"Array size is: " << inTransHist.size() << std::endl;
					for (int i = 0; i < inTransHist.size(); i++){
						std::cout << i << ". " << inTransHist[i]->orderTime;
					}

					std::cout << "Please select which transaction to view or enter -1 to exit: ";
					std::cin >> sel;

					if (sel >= 0 && sel < inTransHist.size()){
						inTransHist[sel]->viewOrder();
					}
					else if ( sel == -1){
						std::cout << "Returning to menu\n";
					}
					else{
						std::cout << "Please select within the range or enter -1 to exit";
					}
				}
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

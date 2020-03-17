#include "FoodItem.hpp"
#include <iostream>

void adminLogin();
void customerLogin();

int main(){

	std::cout <<"FOOD ORDERING SYSTEM DEMO" << std::endl;

	int comInput = 0;

	while (comInput != 9){
		//prompt & get command input
		std::cout << "Select profile to login: " << std::endl;
		std::cout << "1. ADMIN" << std::endl;
		std::cout << "2. CUSTOMER" << std::endl;
		std::cout << "9. Exit program" << std::endl;

		std::cin >> comInput;

		switch(comInput){
			case 1:
				adminLogin();
				break;

			case 2:
				customerLogin();
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

void adminLogin(){
	std::cout << "Logging in as Admin..." <<std::endl;
}


void customerLogin(){
	std::cout << "Logging in as Customer..." <<std::endl;
}
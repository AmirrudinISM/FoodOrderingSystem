#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP

#include "Order.hpp"
#include <vector>
#include <string> 

class Transaction{
public:

	std::vector<Order*> transactionHistory;
	Transaction(){}
	~Transaction(){}
	
};
#endif
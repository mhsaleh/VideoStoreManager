// @file customer.h
// @author Alejandro Alfaro
// @author Muhammed Saleh

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "history.h"
#include <string>
using namespace std;

//---------------------------------------------------------------------------
// Implements a customer class with history, customer ID, and name
// Inherits from history and defines functionality for creating
// customers, get customer ID, update history, and print history

class Customer {

public:
	// constructor
	Customer(int customerID = 0, string lastName = "", 
		     string firstName = "");

	int getCustomerID();		
	void updateHistory(Transaction* transaction);	//adds transaction
	void printHistory() const;

	friend ostream& operator<<(ostream& output, const Customer& customer);

protected:
	History history;		//transaction history of customer
	int customerID;			//unique customer ID
	string lastName;
	string firstName;
};

#endif
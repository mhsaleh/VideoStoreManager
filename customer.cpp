// @file customer.cpp
// @author Alejandro Alfaro
// @author Muhammed Saleh

#ifndef CUSTOMER_CPP
#define CUSTOMER_CPP

#include "customer.h"

//---------------------------------------------------------------------------
// Implements a customer class with history, customer ID, and name
// Inherits from history and defines functionality for creating
// customers, get customer ID, update history, and print history

// ---------------------------------------------------------------------------
// Constructor
// Assigns the customerID, lastName, and firstName to its 
// equivalent passed parameters
Customer::Customer(int customerID, string lastName, string firstName) {
	this->customerID = customerID;
	this->lastName = lastName;
	this->firstName = firstName;
}

// ---------------------------------------------------------------------------
// getCustomer
int Customer::getCustomerID() {
	return customerID;
}

// ---------------------------------------------------------------------------
// updateHistory
// Inserts the passed transaction to the customer history
void Customer::updateHistory(Transaction* transaction) {
	history.insert(transaction);
}

// ---------------------------------------------------------------------------
// printHistory
// Prints the history of the current customer
void Customer::printHistory() const {
	cout << history;
}

// ---------------------------------------------------------------------------
// operator<<
// Prints customer last name and first name.
ostream& operator<<(ostream& output, const Customer& customer) {
	output << "  *** Customer ID = " 
		   << customer.customerID 
		   << " " << customer.lastName 
		   << " " << customer.firstName;
	return output;
}


#endif

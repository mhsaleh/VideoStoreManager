// @file hashtable.cpp
// @author Alejandro Alfaro
// @author Muhammed Saleh

#ifndef HASHTABLE_CPP
#define HASHTABLE_CPP

#include "hashtable.h"

//---------------------------------------------------------------------------
// Implements a HashTable class which stores customers 
// Inherits from customer and defines functionality for storing
// customer objects using customer, inserting,
// retrieving, and printing the hastable of customers.


// ---------------------------------------------------------------------------
// Constructor
// Default constructor for Hashtable class, initializes customerTable 
// and sets the elements to NULL
HashTable::HashTable() {
	customerTable = new Customer*[MAX_CUSTOMERS];
	for (int i = 0; i < MAX_CUSTOMERS; i++) {
		customerTable[i] = NULL;
	}
}

// ---------------------------------------------------------------------------
// Destructor
HashTable::~HashTable() {
	for (int i = 0; i < MAX_CUSTOMERS; i++) {
		delete customerTable[i];
		customerTable[i] = NULL;
	}
	delete[] customerTable;
}

// ---------------------------------------------------------------------------
// insert
// inserts the given customer in the hashtable, the customer is placed
// in the corresponding element accorind to customerID 
bool HashTable::insert(Customer* newCustomer) {
	//checks for valid customerID eg. 1000-9998
	if (newCustomer->getCustomerID() >= MIN_CUSTOMER_ID 
		&& newCustomer->getCustomerID() < MAX_CUSTOMERS - 1) {
		customerTable[newCustomer->getCustomerID()] = newCustomer;
		return true;		//successful additon
	} else {
		cout << "Initialization Error: invalid customer ID" << endl;
		delete newCustomer;		//reclaims memory from invalid ID
		return false;
	}
}

// ---------------------------------------------------------------------------
// retreive
// checks the hashtable with the given ID and sets it to the passed empty 
// customer if found.
bool HashTable::retrieve(int ID, Customer*& customer){
	//checks for valid ID
	if (ID >= MIN_CUSTOMER_ID && ID < MAX_CUSTOMERS - 1) {
		customer = customerTable[ID]; 
		if (customer == NULL) {		//customer doesn't exist
			return false;
		} else {
			return true;
		}
	}
	return false;
}

// ---------------------------------------------------------------------------
// printContents
// prints the customers' ID  
void HashTable::printContents() {
	for (int i = 0; i < MAX_CUSTOMERS; i++) {
		if (customerTable[i] != NULL) {
			cout << customerTable[i]->getCustomerID() << endl;
		}
	}
}

#endif
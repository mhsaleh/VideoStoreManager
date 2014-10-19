// @file hashtable.h
// @author Alejandro Alfaro
// @author Muhammed Saleh

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "customer.h"
#include <iostream>

//---------------------------------------------------------------------------
// Implements a HashTable class which stores customers 
// Inherits from customer and defines functionality for storing
// customer objects using customer, inserting into,
// retrieving from, and printing the hastable of customers.

class HashTable {

public:
	HashTable();	//default constructor
	~HashTable();	//destructor

	bool insert(Customer* newCustomer);
	bool retrieve(int ID, Customer*& customer);//retreive customer with ID
	void printContents();		//prints the customers

protected:
	static const int MAX_CUSTOMERS = 10000;
	static const int MIN_CUSTOMER_ID = 1000;

	Customer** customerTable; //array of customers
};

#endif
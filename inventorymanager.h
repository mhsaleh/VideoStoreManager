// @file inventorymanager.h
// @author Alejandro Alfaro
// @author Muhammed Saleh

#ifndef INVENTORYMANAGER_H
#define INVENTORYMANAGER_H

#include <iostream>
#include <fstream>

#include "inventory.h"
#include "hashtable.h"
#include "productfactory.h"
#include "transactionfactory.h"

//---------------------------------------------------------------------------
// Implements an inventory manager class for use managing the business 
//    carried out within the store. Includes functionality for initializing
//    and displaying all of the products held by the store, initializing
//    all of the customers within the store, as well as performing 
//    transactions within the store.

class InventoryManager {

public:
	//InventoryManager(); 	// constructor  
	//~InventoryManager();  // destructor
  
	void initializeProducts(string productFile);  // initialize inventory
	void initializeCustomers(string customerFile);// initialize customers
	void processTransactionList(string fileName); // process transactions

private:
	// helper methods for processTransactionList
	// display contents of inventory
	void displayInventory() const;
	// display customer history
	bool displayCustomerHistory(ifstream& transactionInput); 
	// preform transaction and add to customer history if valid
	void performTransaction(ifstream& transactionInput,
							Transaction* newTransaction);

 
	Inventory products;   // inventory object for storing products
	HashTable customers;  // hashtable of customers

	ProductFactory productFactory;
	TransactionFactory transactionFactory;
};

#endif
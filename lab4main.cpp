// @file lab4main.cpp
// @author Alejandro Alfaro
// @author Muhammed Saleh

#include "inventorymanager.h"

//---------------------------------------------------------------------------
// Main method for initializing and running the business of the store.
//
// Assumptions:
//    - All filenames must be valid
//    - All text files must be formatted correctly

const string productFileName = "data4movies.txt";
const string customerFileName = "data4customers.txt";
const string commandFileName = "data4commands.txt";

int main() {

	 InventoryManager store;
    
	// initialization
	store.initializeProducts(productFileName);
	store.initializeCustomers(customerFileName);
   
   // run business
	store.processTransactionList(commandFileName);
	
	return -1;
}

 
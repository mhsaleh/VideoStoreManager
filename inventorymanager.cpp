// @file inventorymanager.cpp
// @author Alejandro Alfaro
// @author Muhammed Saleh

#ifndef INVENTORYMANAGER_CPP
#define INVENTORYMANAGER_CPP

#include "inventorymanager.h"

//---------------------------------------------------------------------------
// Implements an inventory manager class for use managing the business 
//    carried out within the store. Includes functionality for initializing
//    and displaying all of the products held by the store, initializing
//    all of the customers within the store, as well as performing 
//    transactions within the store.


// ---------------------------------------------------------------------------
// initializeProducts
// Takes in a string filename and initializes the store inventory based on
// the contents of that file.
void InventoryManager::initializeProducts(string productFileName) {
	ifstream productInput(productFileName.c_str()); // new ifstream
	while (!productInput.eof()) {
		char identifier;
		productInput >> identifier; // get identifier

		if (!productInput.eof()) {
			// create a product with that identifier
			Movie* newProduct = productFactory.createIt(identifier);
			if (newProduct != NULL) { // valid identifier
				char temp = productInput.get(); // skips blank space
				
				// set data for that product with the file
				newProduct->setData(productInput);

				// insert product into its tree
				products.insertProduct(newProduct, identifier);
			} else { 
				cout << "Initialization Error: invalid product identifier."
					 << endl;
				string temp;
				getline(productInput, temp);
			}
		}
	}
	productInput.close();
}

// ---------------------------------------------------------------------------
// initializeProducts
// Takes in a string filename and initializes the store inventory based on
// the contents of that file.
void InventoryManager::displayInventory() const {
	products.display();
}

// ---------------------------------------------------------------------------
// initializeCustomers
// Takes in a string filename and initializes the store customer hashtable
// based on the contents of that file.
void InventoryManager::initializeCustomers(string customerFileName) {
	ifstream customerInput(customerFileName.c_str());
	while (!customerInput.eof()) {
		int customerID;
		string lastName;
		string firstName;
		
		customerInput >> customerID; // get customerID
		customerInput >> lastName;   // get lastName
		customerInput >> firstName;  // get firstName
		
		// skip to next line
		string temp;
		getline(customerInput, temp);
		
		if (!customerInput.eof()) {
			// create and insert new customer
			Customer* temp = new Customer(customerID, lastName, firstName);
			customers.insert(temp);
		}
		
	}
	customerInput.close();
}

// ---------------------------------------------------------------------------
// processTransactionList
// Takes in a string filename and processes transactions on the inventory
// based on the commands in that file.
void InventoryManager::processTransactionList(string transactionFileName) {
	ifstream transactionInput(transactionFileName.c_str());
	while (!transactionInput.eof()) {

		char identifier;
		transactionInput >> identifier; // get transaction identifier

		if (!transactionInput.eof()) {
			Transaction* newTransaction = // make a new transaction
						 transactionFactory.createIt(identifier);

			if (newTransaction != NULL) { // transaction
				performTransaction(transactionInput, newTransaction);
			} else if (identifier == 'S') { // print inventory
				displayInventory();
			} else if (identifier == 'H') { // print history
				displayCustomerHistory(transactionInput);
			} else { // invalid identifier
				cout << "Transaction Error: invalid transaction command." 
					 << endl;
			}
			// skip to next line
			string temp;
			getline(transactionInput, temp);
		}
	}
	transactionInput.close();
}

// ---------------------------------------------------------------------------
// performTransaction
// Helper method for process transaction. Takes in an ifstream and a
// transaction object and performs the propper transaction. Displays
// error messages if transactions are invalid in any way.
void InventoryManager::performTransaction(ifstream& transactionInput, 
										  Transaction* newTransaction) {
	int customerID;
	transactionInput >> customerID; // get customerID

	char mediaType;
	transactionInput >> mediaType;  // get mediaType

	char movieIdentifier;
	transactionInput >> movieIdentifier; // get movieIdentifier

	char temp = transactionInput.get(); // reads unwanted blank space

	if (mediaType == 'D') { // valid mediatype
		Movie* tempProduct = NULL;
		// make a temp product
		tempProduct = productFactory.createIt(movieIdentifier);
		if (tempProduct != NULL) {
			// set product data with file
			tempProduct->setPartialData(transactionInput);

			Movie* product = NULL;
			// retrieve product matching temp from tree
			// true if the product was retrieved
			if (products.getProduct(tempProduct, product,
									movieIdentifier)) {
				// make a temp customer
				Customer* temp = NULL;
				// retrieve customer from table
				// true if customer was retrieved
				if (customers.retrieve(customerID, temp)) {
					// execute transaction
					// true if transaction was successful
					if (newTransaction->execute(product)) {
						temp->updateHistory(newTransaction);
					} else { // unsuccessful transaction
						delete newTransaction;
					}
				} else { // customer not found
					delete newTransaction;
					cout << "Transaction Error: invalid customer." << endl;
				}
			} else { // product not found
				delete newTransaction;
				cout << "Transaction Error: invalid product." << endl;
			}
			delete tempProduct;
		} else { // invalid product identifier
			delete newTransaction;
			cout << "Transaction Error: invalid product identifier." << endl;
		}
	} else { // invalid media type (not D)
		delete newTransaction;
		cout << "Transaction Error: invalid media type." << endl;
	}
}
// ---------------------------------------------------------------------------
// displayCustomerHistory
// Helper method for processTransactionList. Takes in an ifstream and 
// displayes the history of the customer on the current line of the
// ifstream.
bool InventoryManager::displayCustomerHistory(ifstream& transactionInput) {
	int customerID;
	transactionInput >> customerID; // get customerID

	Customer* tempCustomer = NULL;
	// retrieve customer based on ID
	if (customers.retrieve(customerID, tempCustomer)) {
		cout << *tempCustomer << endl; // print customer name and ID
		tempCustomer->printHistory();  // print customer history
		return true;
	} else { // customer not retrieved
		cout << "Error: this customer does not exist" << endl;
		return false;
	}
}

#endif
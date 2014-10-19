// @file transactionfactory.cpp
// @author Alejandro Alfaro
// @author Muhammed Saleh

#ifndef TRANSACTIONFACTORY_CPP
#define TRANSACTIONFACTORY_CPP

#include "transactionfactory.h"

//---------------------------------------------------------------------------
// Implements a transaction factory for the initialization of transactions 
//    within the store. Stores transactions within a hashtable.

//---------------------------------------------------------------------------
// Constructor
// Constructor for transaction factory class which initializes the hashtable
// to the propper transactions.
TransactionFactory::TransactionFactory() {
	for (int i = 0; i < MAX_PRODUCTS; i++) {
		tFactory[i] = NULL;
	}
	tFactory['B' - 'A'] = new Borrow();
	tFactory['R' - 'A'] = new Return();
}

//---------------------------------------------------------------------------
// Destructor
// Destructor for transaction factory class deletes transactions within the 
// tFactory hashtable.
TransactionFactory::~TransactionFactory() {
    for (int i = 0; i < MAX_PRODUCTS; i++) {
		delete tFactory[i];
		tFactory[i] = NULL;
    }
}

//---------------------------------------------------------------------------
// createIt
// CreateIt method takes in a character and returns the transaction 
// object in the hashtable that corresponds to that character.
Transaction* TransactionFactory::createIt(char ch) const {
	int subscript = hashFactory(ch);
	if (tFactory[subscript] == NULL) {
		return NULL;
	} else {
		return tFactory[subscript]->create();
	}
}

//---------------------------------------------------------------------------
// hashFactory
// HashFactory method takes in a character and returns the corresponding
// index for that character in the hashtable.
int TransactionFactory::hashFactory(char ch) const {
	return ch - 'A';
}

#endif
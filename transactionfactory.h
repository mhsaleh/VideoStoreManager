// @file transactionfactory.h
// @author Alejandro Alfaro
// @author Muhammed Saleh

#ifndef TRANSACTIONFACTORY_H
#define TRANSACTIONFACTORY_H

#include "transaction.h"
#include "borrow.h"
#include "return.h"

//---------------------------------------------------------------------------
// Implements a transaction factory for the initialization of transactions 
//    within the store. Stores transactions within a hashtable.

class TransactionFactory {

public:
    TransactionFactory();	// constructor
    ~TransactionFactory();  // destructor

    Transaction* createIt(char ch) const; // create a transaction

private:
	// max number of products
	static const int MAX_PRODUCTS = 26;

	int hashFactory(char ch) const;  // helper hashing method

    Transaction* tFactory[MAX_PRODUCTS]; // array of transaction objects
};

#endif
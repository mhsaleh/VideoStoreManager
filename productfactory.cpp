// @file productfactory.cpp
// @author Alejandro Alfaro
// @author Muhammed Saleh

#ifndef PRODUCTFACTORY_CPP
#define PRODUCTFACTORY_CPP

#include "productfactory.h"

//---------------------------------------------------------------------------
// Implements a product factory for the initialization of products within
//    the store. Stores products within a hashtable.

//---------------------------------------------------------------------------
// Constructor
// Constructor for product factory class which initializes the hashtable
// to the propper products.
ProductFactory::ProductFactory() {
	for (int i = 0; i < MAX_PRODUCTS; i++) {
		pFactory[i] = NULL;
	}
	pFactory['C' - 'A'] = new Classic();
    pFactory['D' - 'A'] = new Drama();
    pFactory['F' - 'A'] = new Comedy();
}

//---------------------------------------------------------------------------
// Destructor
// Destructor for product factory class deletes products within the 
// pFactory hashtable.
ProductFactory::~ProductFactory() {
    for (int i = 0; i < MAX_PRODUCTS; i++) {
		delete pFactory[i];
		pFactory[i] = NULL;
	}
}

//---------------------------------------------------------------------------
// createIt
// CreateIt method takes in a character and returns the movie object in the
// hashtable that corresponds to that character.
Movie* ProductFactory::createIt(char ch) const {
	int subscript = hashFactory(ch);
	if (pFactory[subscript] == NULL) {
		return NULL;
	} else {
		return pFactory[subscript]->create();
	}
}

//---------------------------------------------------------------------------
// hashFactory
// HashFactory method takes in a character and returns the corresponding
// index for that character in the hashtable.
int ProductFactory::hashFactory(char ch) const {
	return ch - 'A';
}

#endif
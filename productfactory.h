// @file productfactory.h
// @author Alejandro Alfaro
// @author Muhammed Saleh

#ifndef PRODUCTFACTORY_H
#define PRODUCTFACTORY_H

#include "movie.h"
#include "drama.h"
#include "classic.h"
#include "comedy.h"

//---------------------------------------------------------------------------
// Implements a product factory for the initialization of products within
//    the store. Stores products within a hashtable.

class ProductFactory {

public:
    ProductFactory();	// constructor
    ~ProductFactory();  // destructor

    Movie* createIt(char ch) const; // create a product

private:
	// max number of products
	static const int MAX_PRODUCTS = 26;

	int hashFactory(char ch) const;  // hashing helper method

    Movie* pFactory[MAX_PRODUCTS]; // array of product objects
};

#endif
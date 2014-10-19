// @file transaction.h
// @author Alejandro Alfaro
// @author Muhammed Saleh

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <iostream>
#include <fstream>
#include "movie.h"
using namespace std;

//---------------------------------------------------------------------------
// Implements a transaction class for use storing transactions in customer
//    history. Defines pure virtual methods that are meant to be inherited
//    including functionality for creating transactions using the factory,
//    setting the data with the transaction, as well as displaying the 
//    transaction.

class Transaction {

public:
   Transaction(); // constructor

   virtual Transaction* create() const = 0; // used by factory
   virtual bool execute(Movie* movie) = 0;  // set the transaction data
   
   virtual void display() const = 0; // display transaction information
};

#endif
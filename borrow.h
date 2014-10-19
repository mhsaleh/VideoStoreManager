// @file borrow.h
// @author Alejandro Alfaro
// @author Muhammed Saleh

#ifndef BORROW_H
#define BORROW_H

#include "transaction.h"

//---------------------------------------------------------------------------
// Implements a borrow class for use storing borrows in customer history. 
//    Inherits from transaction and defines functionality for creating
//    borrow objects using the factory, setting the data within the 
//    borrow objects, as well as displaying the content of borrow objects.

class Borrow : public Transaction {

public:
	Borrow(Movie* movie = NULL); // constructor
	~Borrow(); // destructor

	virtual Transaction* create() const; // used by factory
	virtual bool execute(Movie* movie);  // set the borrow data

	virtual void display() const; // display borrow information

protected:
	Movie* movie; // movie that was borrowed
};

#endif
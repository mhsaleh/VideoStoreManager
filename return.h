// @file return.h
// @author Alejandro Alfaro
// @author Muhammed Saleh

#ifndef RETURN_H
#define RETURN_H

#include "transaction.h"

//---------------------------------------------------------------------------
// Implements a return class for use storing returns in customer history. 
//    Inherits from transaction and defines functionality for creating
//    return objects using the factory, setting the data within the 
//    return objects, as well as displaying the content of return objects.

class Return : public Transaction {

public:
	Return(Movie* movie = NULL); // constructor
	~Return(); // destructor

	virtual Transaction* create() const; // used by factory
	virtual bool execute(Movie* movie); // set the return data

	virtual void display() const; // display return information

protected:
	Movie* movie; // movie that was returned
};

#endif
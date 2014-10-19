// @file return.cpp
// @author Alejandro Alfaro
// @author Muhammed Saleh

#ifndef RETURN_CPP
#define RETURN_CPP

#include "return.h"

//---------------------------------------------------------------------------
// Implements a return class for use storing returns in customer history. 
//    Inherits from transaction and defines functionality for creating
//    return objects using the factory, setting the data within the 
//    return objects, as well as displaying the content of return objects.

// ---------------------------------------------------------------------------
// Constructor
// Default constructor for return class, calls transaction constructor
Return::Return(Movie* movie) : Transaction() { 
	this->movie = movie;
}

// ---------------------------------------------------------------------------
// Destructor
// Destructor for return class, deletes movie pointer.
Return::~Return() {
	delete movie;
}

// ---------------------------------------------------------------------------
// Create
// Create method for use in the factory. Returns a new return object.
Transaction* Return::create() const {
	return new Return();
}

// ---------------------------------------------------------------------------
// setData
// SetData method sets the movie in the return object to a passed in movie
// object.
bool Return::execute(Movie* movie) {
	if (movie->getCount() < 10) {
		movie->returnMovie();
		this->movie = movie;
		return true;
	} else {
		cout << "Transaction Error: this product has not yet been borrowed."
			 << endl;
		return false;
	}
}

// ---------------------------------------------------------------------------
// display
// display method displays the contents of the return object including the
// mediatype and movie contained by the borrow object.
void Return::display() const {
	cout << "DVD "
	     << "Return ";
	if (movie != NULL) {
		movie->display(cout);
	} 
	cout << endl;
}

#endif
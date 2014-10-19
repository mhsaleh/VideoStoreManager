// @file borrow.cpp
// @author Alejandro Alfaro
// @author Muhammed Saleh

#ifndef BORROW_CPP
#define BORROW_CPP

#include "borrow.h"

//---------------------------------------------------------------------------
// Implements a borrow class for use storing borrows in customer history. 
//    Inherits from transaction and defines functionality for creating
//    borrow objects using the factory, setting the data within the 
//    borrow objects, as well as displaying the content of borrow objects.

// ---------------------------------------------------------------------------
// Constructor
// Default constructor for borrow class, calls transaction constructor
Borrow::Borrow(Movie* movie) : Transaction() { 
	this->movie = movie;
}

// ---------------------------------------------------------------------------
// Destructor
// Destructor for borrow class, deletes movie pointer.
Borrow::~Borrow() {
	delete movie;
}

// ---------------------------------------------------------------------------
// Create
// Create method for use in the factory. Returns a new borrow object.
Transaction* Borrow::create() const {
	return new Borrow();
}

// ---------------------------------------------------------------------------
// setData
// SetData method sets the movie in the borrow object to a passed in movie
// object.
bool Borrow::execute(Movie* movie) {
	this->movie = movie;
	// if there are movies in stock to borrow
	if (movie->getCount() > 0) {
		movie->borrowMovie(); // decrease count
		this->movie = movie;
		return true;
	} else {
		cout << "Transaction Error: all copies of "
			 << "this product have been borrowed." 
			 << endl;
		return false;
	}
}

// ---------------------------------------------------------------------------
// display
// display method displays the contents of the borrow object including the
// mediatype and movie contained by the borrow object.
void Borrow::display() const {
	cout << "DVD "
		 << "Borrow ";
	if (movie != NULL) {
		movie->display(cout);
	}
	cout << endl;
}

#endif
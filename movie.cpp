// @file movie.cpp
// @author Alejandro Alfaro
// @author Muhammed Saleh

#ifndef MOVIE_CPP
#define MOVIE_CPP

#include "movie.h"

//---------------------------------------------------------------------------
// Implements movie class which creates movies 
// Defines functionality for setting data in the objects, boolean operators
// borrow and return, get/display count, and display movie.

// ---------------------------------------------------------------------------
// Constructor
// initializes count to the passed value
Movie::Movie(int count) { 
	this->count = count;
}

// ---------------------------------------------------------------------------
// destructor
// deletes strings properly
Movie::~Movie() {}

// ---------------------------------------------------------------------------
// borrowMovie
// count is subtracted by one each time a movie is borrowed
void Movie::borrowMovie() {
	count--;
}

// ---------------------------------------------------------------------------
// returnovie
// count is added by one each time a movie is returned
void Movie::returnMovie() {
	count++;
}

// ---------------------------------------------------------------------------
// getCount
int Movie::getCount() const {
	return count;
}

// ---------------------------------------------------------------------------
// operator<<
// calls displayCount and display for the specified movie
ostream& operator<<(ostream& output, const Movie& movie) {
	movie.displayCount(output);		//count is displayed
	movie.display(output);			//conents for the movie are displayed
	return output;
}

// ---------------------------------------------------------------------------
// displayCount
// count displays available movies and movies borrowed.
void Movie::displayCount(ostream& output) const {
	output.setf(ios::left, ios::adjustfield);
	output  << setw(IN_SPACING) << count 
		    << setw(OUT_SPACING) << (DEFAULT_STOCK - count);
}

#endif
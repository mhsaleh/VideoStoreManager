// @file movie.h
// @author Alejandro Alfaro
// @author Muhammed Saleh

#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip> 
using namespace std;

//---------------------------------------------------------------------------
// Implements movie class which creates movies 
// Defines functionality for setting data in the objects, boolean operators
// borrow and return, get/display count, and display movie.

class Movie {

public:
   // constructor
   Movie(int count = DEFAULT_STOCK);
   virtual ~Movie() = 0;

   // boolean operators to determine sorting order
   virtual bool operator==(const Movie& right) const = 0;      // equality
   virtual bool operator!=(const Movie& right) const = 0;      // inequality
   virtual bool operator>(const Movie& right) const = 0;       // greater than
   virtual bool operator<(const Movie& right) const = 0;       // less than

   virtual Movie* create() const = 0;    // used by factory
   virtual bool setData(ifstream& dataFile) = 0; //complete data
   virtual bool setPartialData(ifstream& dataFile) = 0; //partial data 

   // transactions
   void borrowMovie();	// decrease count
   void returnMovie();  // increase count

   int getCount() const;

   friend ostream& operator<<(ostream& output, const Movie& movie);
   virtual void display(ostream& output) const = 0;	//display movie object
   void displayCount(ostream& output) const;		

protected:
	// output spacing constants
	static const int DEFAULT_STOCK = 10; // the default number of products in stock
	static const int IN_SPACING = 4;
	static const int OUT_SPACING = 4;
	static const int TITLE_SPACING = 23;
	static const int DIRECTOR_SPACING = 19;
	static const int YEAR_SPACING = 5;
	static const int MONTH_SPACING = 3;
	static const int ACTOR_MAX_LENGTH = 21;

    int count; // number of products in stock
};

#endif
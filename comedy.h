// @file comedy.h
// @author Alejandro Alfaro
// @author Muhammed Saleh

#ifndef COMEDY_H
#define COMEDY_H

#include "movie.h"

//---------------------------------------------------------------------------
// Implements a comedy class which is used to create comedy movie objects. 
// Inherits from movie and defines functionality for sorting,
// set partial and complete data, and display comedy objects

class Comedy : public Movie {


public:
	// constructor
	Comedy(string title = "", int year = 0,	
		   string director = "", int count = DEFAULT_STOCK);
	~Comedy();
	
	// boolean operators to determine sorting order
	virtual bool operator==(const Movie& right) const;      // equality
	virtual bool operator!=(const Movie& right) const;      // inequality
	virtual bool operator>(const Movie& right) const;       // greater than
	virtual bool operator<(const Movie& right) const;       // less than

	virtual Movie* create() const;					// used by factory
	virtual bool setData(ifstream& dataFile);		//set complete data
	virtual bool setPartialData(ifstream& dataFile);//partial data

	friend ostream& operator<<(ostream& output, const Movie& movie);
    virtual void display(ostream& output) const;	//display object

protected:
	string director;  // first and last name
	string title;     // title of the film
	int year;         // date
};

#endif
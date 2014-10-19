// @file drama.h
// @author Alejandro Alfaro
// @author Muhammed Saleh

#ifndef DRAMA_H
#define DRAMA_H

#include "movie.h"

//---------------------------------------------------------------------------
// Implements a drama class which is used to create drama objects. 
// Inherits from movie and defines functionality for sorting,
// set partial and complete data, and display drama objects

class Drama : public Movie {

public:
	// constructor
	Drama(string director = "", string title = "", 
		  int year = 0, int count = DEFAULT_STOCK);
	~Drama();
   
	// boolean operators to determine sorting order
	virtual bool operator==(const Movie& right) const;     // equality
	virtual bool operator!=(const Movie& right) const;     // inequality
	virtual bool operator>(const Movie& right) const;      // greater than
	virtual bool operator<(const Movie& right) const;      // less than

    virtual Movie* create() const; // used by factory
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
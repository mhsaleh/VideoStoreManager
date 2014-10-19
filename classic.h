// @file classic.h
// @author Alejandro Alfaro
// @author Muhammed Saleh

#ifndef CLASSIC_H
#define CLASSIC_H

#include "movie.h"

//---------------------------------------------------------------------------
// Implements a classic class which is used to create classic movie objects. 
// Inherits from movie and defines functionality for sorting,
// set partial and complete data, and display classic objects

class Classic : public Movie {

public:
	// constructor
	Classic(int year = 0, int month = 0, string actor = "", 
			string director = "", string title = "",
			int count = DEFAULT_STOCK);
	~Classic();	//destructor
   
	// boolean operators to determine sorting order
	virtual bool operator==(const Movie& right) const;     // equality
	virtual bool operator!=(const Movie& right) const;     // inequality
	virtual bool operator>(const Movie& right) const;      // greater than
	virtual bool operator<(const Movie& right) const;      // less than

	virtual Movie* create() const;					// used by factory
	virtual bool setData(ifstream& dataFile);		//set complete data
	virtual bool setPartialData(ifstream& dataFile);//partial data 

	friend ostream& operator<<(ostream& output, const Movie& movie);
	virtual void display(ostream& output) const;	//display object

protected:
	string director;  // first and last name
	string title;     // title of the film
	string actor;     // first and last name

	int year;         // date
	int month;
};

#endif
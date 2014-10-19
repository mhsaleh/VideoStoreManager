// @file classic.cpp
// @author Alejandro Alfaro
// @author Muhammed Saleh

#ifndef CLASSIC_CPP
#define CLASSIC_CPP

#include "classic.h"

//---------------------------------------------------------------------------
// Implements a classic class which creates classic movie objects. 
// Inherits from movie and defines functionality for sorting,
// set partial and complete data, and display classic objects


// ---------------------------------------------------------------------------
// Constructor
// initializes the variables in classic to the passed parameters. 
// calls movie constructor to initialize count
Classic::Classic(int year, int month, string actor, 
				 string director, string title, int count)
			     : Movie(count) { 
	
	this->director = director;
	this->title = title;
	this->actor = actor;
	this->year = year;
	this->month = month;
}

// ---------------------------------------------------------------------------
// destructor
Classic::~Classic() {}

// ---------------------------------------------------------------------------
// operator==
// compares classic movie objects by year, month, and actor 
bool Classic::operator==(const Movie& right) const {
	// typecast to classic object
	const Classic& tempClassic = (const Classic&) right; 
	return (year == tempClassic.year) && 
			(month == tempClassic.month) && (actor == tempClassic.actor);
}

// ---------------------------------------------------------------------------
// operator !=
// compares classic movie objects by year, month, and actor 
bool Classic::operator!=(const Movie& right) const {
	//turn movie object to classic object
	const Classic& tempClassic = (const Classic&) right;
	return (year != tempClassic.year) && 
			(month != tempClassic.month) && (actor != tempClassic.actor);
}

// ---------------------------------------------------------------------------
// operator>
// compares classic movie objects by year, then month, and then actor
bool Classic::operator>(const Movie& right) const {
	// typecast to classic object
	const Classic& tempClassic = (const Classic&) right;
	if (year == tempClassic.year) {						//same year
		if (month == tempClassic.month) {				//same month
			return actor > tempClassic.actor;
		} else {
			return month > tempClassic.month;
		}
	} else {
		return year > tempClassic.year;
	}
}

// ---------------------------------------------------------------------------
// operator<
// compares classic movie objects by year, then month, and then actor
bool Classic::operator<(const Movie& right) const {
	// typecast to classic object
	const Classic& tempClassic = (const Classic&) right;
	if (year == tempClassic.year) {		//same year
		if (month == tempClassic.month) {	//same month
			return actor < tempClassic.actor;
		} else {
			return month < tempClassic.month;
		}
	} else {
		return year < tempClassic.year;
	}
}

// ---------------------------------------------------------------------------
// create
// used by Factory, creates a classic object
Movie* Classic::create() const {
	return new Classic();
}

// ---------------------------------------------------------------------------
// setData
// Takes in an ifstream and sets the data in the object based
// on the contents of that file
bool Classic::setData(ifstream& dataFile) {
	
	char currentChar = dataFile.get();	//gets spaces
	
	string directorName = "";
	
	while (currentChar != ',') {
		directorName.append(string(1, currentChar));//gets directorName
		currentChar = dataFile.get();
	}
	
	director = directorName;	
	
	currentChar = dataFile.get();	// gets space

	string movieTitle = "";
	currentChar = dataFile.get();	// gets name of movie

	while (currentChar != ',') {
		movieTitle += currentChar;	
		currentChar = dataFile.get(); // gets commas
	}

	title = movieTitle;
	currentChar = dataFile.get(); //gets space

	string firstName;
	string lastName;

	dataFile >> firstName;		// actor first name
	dataFile >> lastName;		// actor last name

	actor = firstName + " " + lastName; // combine for name

	dataFile >> month;		//sets month
	dataFile >> year;		//sets year

	getline(dataFile, firstName); // go to next line
	
	return true;
}

// ---------------------------------------------------------------------------
// setPartialData
// Takes in an iftsream with partial data and sets the data in the object
// based on this ifstream. Partial data includes at least the 
// data members that are used for comparisons
bool Classic::setPartialData(ifstream& dataFile) {
	dataFile >> month;			//sets month
	dataFile >> year;			//sets year

	string firstName;
	string lastName;

	dataFile >> firstName;		// actor first name
	dataFile >> lastName;		// actor last name

	actor = firstName + " " + lastName; // combine for name
	return true;
}

// ---------------------------------------------------------------------------
// display
// displays a classic object to the console
void Classic::display(ostream& output) const {
	output.setf(ios::left, ios::adjustfield);
	output << setw(TITLE_SPACING) << title.substr(0, TITLE_SPACING - 1)
		   << setw(DIRECTOR_SPACING)
		   << director.substr(0, DIRECTOR_SPACING - 1)
		   << setw(YEAR_SPACING) << year
		   << setw(MONTH_SPACING) << month 
		   << actor.substr(0, ACTOR_MAX_LENGTH);

}

#endif
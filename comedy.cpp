// @file comedy.cpp
// @author Alejandro Alfaro
// @author Muhammed Saleh

#ifndef COMEDY_CPP
#define COMEDY_CPP

#include "comedy.h"

//---------------------------------------------------------------------------
// Implements a comedy class which is used to create comedy movie objects. 
// Inherits from movie and defines functionality for sorting,
// set partial and complete data, and display comedy objects


// ---------------------------------------------------------------------------
// Constructor
// initializes the variables in comedy to the passed parameters. 
// calls movie constructor to initialize count
Comedy::Comedy(string title, int year, string director, int count)
			   : Movie(count) {

	this->director = director;
	this->title = title;
	this->year = year;
}

// ---------------------------------------------------------------------------
// destructor
Comedy::~Comedy() {}

// ---------------------------------------------------------------------------
// operator==
// compares comedy movie objects by title, and year
bool Comedy::operator==(const Movie& right) const {
	// typecast to comedy object
	const Comedy& tempComedy = (const Comedy&) right;
	return (title == tempComedy.title) && (year == tempComedy.year);
}

// ---------------------------------------------------------------------------
// operator !=
// compares comedy movie objects by title, and year
bool Comedy::operator!=(const Movie& right) const {
	// typecast to comedy object
	const Comedy& tempComedy = (const Comedy&) right;
	return (title != tempComedy.title) && (year != tempComedy.year);
}

// ---------------------------------------------------------------------------
// operator>
// compares comedy movie objects by title, then year
bool Comedy::operator>(const Movie& right) const {
	// typecast to comedy object
	const Comedy& tempComedy = (const Comedy&) right;
	if (title == tempComedy.title) {				//same title
		return year > tempComedy.year;
	} else {
		return title > tempComedy.title;
	}
}

// ---------------------------------------------------------------------------
// operator<
// compares comedy movie objects by title, then year
bool Comedy::operator<(const Movie& right) const {
	// typecast to comedy object
	const Comedy& tempComedy = (const Comedy&) right;
	if (title == tempComedy.title) {	//same title
		return year < tempComedy.year;
	} else {
		return title < tempComedy.title;
	}
}

// ---------------------------------------------------------------------------
// create
// used by Factory, creates a comedy object
Movie* Comedy::create() const {
	return new Comedy();
}

// ---------------------------------------------------------------------------
// setData
// Takes in an ifstream and sets the data in the object based
// on the contents of that file
bool Comedy::setData(ifstream& dataFile) {
	
	char currentChar = dataFile.get(); //gets director name
	string directorName = "";

	while (currentChar != ',') {
		directorName += currentChar;
		currentChar = dataFile.get(); //gets next character
	}

	director = directorName;
	currentChar = dataFile.get();	// skip unwanted space

	string movieTitle = "";
	currentChar = dataFile.get();	//gets movie title

	while (currentChar != ',') {
		movieTitle += currentChar;
		currentChar = dataFile.get();	//gets next character
	}

	title = movieTitle;

	dataFile >> year;				//sets year

	getline(dataFile, directorName); // go to next line
	
	return true;
}

// ---------------------------------------------------------------------------
// setPartialData
// Takes in an iftsream with partial data and sets the data in the object
// based on this ifstream. Partial data includes at least the 
// data members that are used for comparisons
bool Comedy::setPartialData(ifstream& dataFile) {
	string movieTitle = "";
	char currentChar = dataFile.get();		//gets movie titel

	while (currentChar != ',') {
		movieTitle += currentChar;
		currentChar = dataFile.get();	//gets next characters
	}

	title = movieTitle;
	dataFile >> year;					//gets year

	return true;
}

// ---------------------------------------------------------------------------
// display
// displays a comedy object to the console
void Comedy::display(ostream& output) const {
	output.setf(ios::left, ios::adjustfield);
	output << setw(TITLE_SPACING) << title.substr(0, TITLE_SPACING - 1)
		   << setw(DIRECTOR_SPACING) 
		   << director.substr(0, DIRECTOR_SPACING - 1)
		   << setw(YEAR_SPACING) << year;
}

#endif
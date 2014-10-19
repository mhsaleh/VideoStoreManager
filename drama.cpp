// @file drama.cpp
// @author Alejandro Alfaro
// @author Muhammed Saleh

#ifndef DRAMA_CPP
#define DRAMA_CPP

#include "drama.h"

//---------------------------------------------------------------------------
// Implements a drama class which is used to create drama movie objects. 
// Inherits from movie and defines functionality for sorting,
// set partial and complete data, and display drama objects


// ---------------------------------------------------------------------------
// Constructor
// initializes the variables in drama to the passed parameters. 
// calls movie constructor to initialize count
Drama::Drama(string director, string title,  int year, int count)
			: Movie(count) { 
	
	this->director = director;
	this->title = title;
	this->year = year;
}

// ---------------------------------------------------------------------------
// destructor
Drama::~Drama() {}

// ---------------------------------------------------------------------------
// operator==
// compares drama movie objects by director, and title
bool Drama::operator==(const Movie& right) const {
	// typecast to drama object
	const Drama& tempDrama = (const Drama&) right;
	return (director == tempDrama.director) && (title == tempDrama.title);
}

// ---------------------------------------------------------------------------
// operator!=
// compares drama movie objects by director, and title
bool Drama::operator!=(const Movie& right) const {
	// typecast to drama object
	const Drama& tempDrama = (const Drama&) right;
	return (director != tempDrama.director) && (title != tempDrama.title);
}

// ---------------------------------------------------------------------------
// operator>
// compares drama movie objects by director, then title
bool Drama::operator>(const Movie& right) const {
	// typecast to drama object
	const Drama& tempDrama = (const Drama&) right;
	if (director == tempDrama.director) {			//same director
		return title > tempDrama.title;
	} else {
		return director > tempDrama.director;
	}
}

// ---------------------------------------------------------------------------
// operator<
// compares drama movie objects by director, then title
bool Drama::operator<(const Movie& right) const {
	// typecast to drama object
	const Drama& tempDrama = (const Drama&) right;
	if (director == tempDrama.director) {			//same director
		return title < tempDrama.title;
	} else {
		return director < tempDrama.director;
	}
}

// ---------------------------------------------------------------------------
// create
// used by Factory, creates a drama object
Movie* Drama::create() const {
	return new Drama();
}

// ---------------------------------------------------------------------------
// setData
// Takes in an ifstream and sets the data in the object based
// on the contents of that file
bool Drama::setData(ifstream& dataFile) {
	
	char currentChar = dataFile.get();			//gets director name
	string directorName = "";

	while (currentChar != ',') {
		directorName += currentChar;
		currentChar = dataFile.get();			//gets next characters
	}

	director = directorName;
	currentChar = dataFile.get();				//gets spaces

	string movieTitle = "";
	currentChar = dataFile.get();				//gets motietitle

	while (currentChar != ',') {
		movieTitle += currentChar;				
		currentChar = dataFile.get();			//gets next characters
		}

	title = movieTitle;

	dataFile >> year;							//sets year

	getline(dataFile, directorName); // go to next line

	return true;
}

// ---------------------------------------------------------------------------
// setPartialData
// Takes in an iftsream with partial data and sets the data in the object
// based on this ifstream. Partial data includes at least the 
// data members that are used for comparisons
bool Drama::setPartialData(ifstream& dataFile) {
	char currentChar = dataFile.get();			//gets director name
	string directorName = "";

	while (currentChar != ',') {
		directorName += currentChar;
		currentChar = dataFile.get();			//gets next characters
	}

	director = directorName;
	currentChar = dataFile.get();				//gets spaces

	string movieTitle = "";
	currentChar = dataFile.get();				//gets movie title

	while (currentChar != ',') {
		movieTitle += currentChar;
		currentChar = dataFile.get();			//gets next characters
	}

	title = movieTitle;

	return true;
}

// ---------------------------------------------------------------------------
// display
// displays a drama object to the console
void Drama::display(ostream& output) const {
	output.setf(ios::left, ios::adjustfield);
	output << setw(TITLE_SPACING) << title.substr(0, TITLE_SPACING - 1)
		   << setw(DIRECTOR_SPACING) 
		   << director.substr(0, DIRECTOR_SPACING - 1)
		   << setw(YEAR_SPACING) << year;
}

#endif
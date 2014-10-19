// @file inventory.h
// @author Alejandro Alfaro
// @author Muhammed Saleh

#ifndef INVENTORY_H
#define INVENTORY_H

#include "bintree.h"

//---------------------------------------------------------------------------
// Implements a inventory class which stores movies in array of bintrees
// Inherits from bintree and defines functionality for inserting
// movie objects, borrow, get, and display movies

class Inventory {

public:
	Inventory();		//constructor
	~Inventory();		//destructor

	bool insertProduct(Movie* product, char tag);	//insert movies
	bool borrowProduct(Movie* product, char tag);	//borrow movies
	bool getProduct(Movie* value, Movie*& product, char tag); //get movies
	void display() const;							//display movies
	void displayHeader() const; // display the header line
private:
	// display header spacing constants
	static const int IN_SPACING = 4;
	static const int OUT_SPACING = 4;
	static const int TITLE_SPACING = 23;
	static const int DIRECTOR_SPACING = 19;
	static const int YEAR_SPACING = 5;
	static const int MONTH_SPACING = 3;
	static const int ACTOR_MAX_LENGTH = 21;

	// number of trees with different products
	static const int TREE_COUNT = 3; 

	BinTree** productTrees;		//bintree of movies
};

#endif
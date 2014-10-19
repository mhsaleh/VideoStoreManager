// @file inventory.cpp
// @author Alejandro Alfaro
// @author Muhammed Saleh

#ifndef INVENTORY_CPP
#define INVENTORY_CPP

#include "inventory.h"

//---------------------------------------------------------------------------
// Implements a inventory class which stores movies in array of bintrees
// Inherits from bintree and defines functionality for inserting
// movie objects, borrow, get, and display movies

// ---------------------------------------------------------------------------
// Constructor
// initializes the array with empty bintrees.
Inventory::Inventory() {
	productTrees = new BinTree*[TREE_COUNT + 1];//size 4 to help hashing
	for (int i = 0; i < TREE_COUNT + 1; i++) {
		productTrees[i] = new BinTree();
	}
}

// ---------------------------------------------------------------------------
// destructor
Inventory::~Inventory() {
	for (int i = 0; i < TREE_COUNT + 1; i++) {
		delete productTrees[i];
	}
	delete[] productTrees;
}

// ---------------------------------------------------------------------------
// insert
// inserts movie into correct tree by subtracting passed char - 'C'
bool Inventory::insertProduct(Movie* product, char tag) {
	productTrees[tag - 'C']->insert(product);
	return true;

}

// ---------------------------------------------------------------------------
// borrowProduct
// calls treeBorrow to borrow a movie.
bool Inventory::borrowProduct(Movie* product, char tag) {
	return productTrees[tag - 'C']->treeBorrow(product);
}

// ---------------------------------------------------------------------------
// getProduct
// calls retreive to get a specific movie.
bool Inventory::getProduct(Movie* value, Movie*& product, char tag) {
	return productTrees[tag - 'C']->retrieve(*value, product);
}

// ---------------------------------------------------------------------------
// display
// displays each element in array, each bintree has its own display.
void Inventory::display() const {
	displayHeader();
	cout << *productTrees[0];
	cout << *productTrees[1];
	cout << *productTrees[3];
}

void Inventory::displayHeader() const {
	cout.setf(ios::left, ios::adjustfield);
	cout << setw(IN_SPACING) << "*IN*"
		 << setw(OUT_SPACING) << "*OUT*" << endl
		 << setw(IN_SPACING) << "DVD"
		 << setw(OUT_SPACING) << "DVD"
		 << setw(TITLE_SPACING) << "TITLE"
		 << setw(DIRECTOR_SPACING) << "DIRECTOR"
		 << setw(YEAR_SPACING) << "YEAR"
		 << setw(MONTH_SPACING) << "MO"
		 << "ACTOR" << endl;
}

#endif
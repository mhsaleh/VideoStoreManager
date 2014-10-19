// @file history.cpp
// @author Alejandro Alfaro
// @author Muhammed Saleh

#ifndef HISTORY_CPP
#define HISTORY_CPP

#include "history.h"

//---------------------------------------------------------------------------
// Implements a history class which stores transactions as Nodes
// Inherits from transaction and defines functionality for storing
// transaction objects, inserting, and printing transactions.

//---------------------------------------------------------------------------
// constructor
// Initializes head to NULL
History::History() {
	head = NULL;
}

//---------------------------------------------------------------------------
// destructor
History::~History() {
	Node* current = head;
	while (current != NULL) {
		Node* next = current->next;
		delete current->transaction;
		delete current;
		current = next;
	}
	head = NULL;
}

//---------------------------------------------------------------------------
// insert
// inserts the given transaction into the history
void History::insert(Transaction* newTransaction) {
	Node* temp = new Node();	//new node initialized
	temp->next = NULL;
	temp->transaction = newTransaction;
	if (head == NULL) {		//history is empty
		head = temp;
	} else {
		Node* current = head;
		while (current->next != NULL) {	//transaction added to history 
			current = current->next;
		}
		current->next = temp;
	}
}

//---------------------------------------------------------------------------
// printHistory
// prints linked list, uses transaction display
void History::printHistory(ostream& output) const {
	Node* current = head;
	while (current != NULL) {
		current->transaction->display();	//calls display 
		current = current->next;
	}
}

//---------------------------------------------------------------------------
// operator<<
// calls printHistory to print a history object
ostream& operator<<(ostream& output, const History& history) {
	history.printHistory(output);
	return output;
}

#endif
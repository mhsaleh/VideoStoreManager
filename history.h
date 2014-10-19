// @file history.h
// @author Alejandro Alfaro
// @author Muhammed Saleh

#ifndef HISTORY_H
#define HISTORY_H

#include "transaction.h"

//---------------------------------------------------------------------------
// Implements a history class which stores transactions as Nodes
// Inherits from transaction and defines functionality for storing
// transaction objects, inserting, and printing transactions.

class History {

friend ostream& operator<<(ostream& output, const History& history);

public:
   History();		// constructor
   ~History();		//destructor

   void insert(Transaction* newTransaction);    // insert into list	
   void printHistory(ostream& output) const;	// prints linked list

private:
	// history linked list
	struct Node {
		Transaction* transaction;	
		Node* next;
    };
	Node* head;
};

#endif
// @file bintree.h
// @author Muhammed Saleh

#ifndef BINTREE_H
#define BINTREE_H

#include "movie.h"

#include <iostream>
using namespace std;

//---------------------------------------------------------------------------
// Implements a Binary Search Tree for storing product objects. Product
//    objects in the left subtree are less than the root, and product
//    objects in the right subtree are greater than the root. Class allows
//    functionality for creation of new BinTree objects using using default
//    custructor, clearing all memory of BinTree objects, inserting a new 
//    product into a bintree, retrieving a product object from a BinTree, 
//    and printing the contents of a bintree inorder.
//
// Modified version of BinTree submitted in Lab 2.

class BinTree {
   // output
   friend ostream& operator<<(ostream& output, const BinTree& tree);
   
   public:
   // constructors and destructor
   BinTree();                     // constructor
   ~BinTree();                    // destructor, calls makeEmpty
   
   // operators
   bool operator==(const BinTree& other) const; // equality
   bool operator!=(const BinTree& other) const; // inequality
   
   // other functions
   bool isEmpty() const;          // true if tree is empty, otherwise false
   void makeEmpty();              // make the tree empty
   bool insert(Movie* value);                // inserts a new node

   bool treeBorrow(Movie* product);

   bool retrieve(const Movie&, Movie*&) const; // retrieves a node
   void displaySideways() const; // displays the tree sideways
   int getDepth(const Movie& value) const; // finds the depth of a node
   void bstreeToArray(Movie* array[]); // converts the tree to an array
   void arrayToBSTree(Movie* array[]); // converts an array to a tree
   
   private:
   struct Node {
      Movie* data; // pointer to data object
      Node* left;     // left subtree pointer
      Node* right;    // right subtree pointer
   };
   Node* root;        // root of the tree
   
   // helper methods
   void makeEmptyHelper(Node*& rootPtr);
   bool insertHelper(Node* rootPtr, Node* temp);
   void inorderHelper(ostream& output, Node* root) const;
   void sideways(Node*, int) const;
   bool equalityHelper(const Node* thisRoot,
   const Node* otherRoot) const;
   bool retrieveHelper(Node* rootPtr, const Movie& value,
                       Movie*& pointer) const;
   //void copyHelper(Node*& thisRoot, Node* otherRoot);
   int getDepthHelper(const Movie& value, Node* rootPtr) const;
   void bstreeToArrayHelper(Movie* array[], Node* rootPtr,
                            int& index) const;
   void arrayToBSTreeHelper(Movie* tempArray[], int low, int high);
};

#endif
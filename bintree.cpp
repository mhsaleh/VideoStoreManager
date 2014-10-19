// @file bintree.cpp
// @author Muhammed Saleh

#ifndef BINTREE_CPP
#define BINTREE_CPP

#include "bintree.h"

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

// ---------------------------------------------------------------------------
// Constructor
// Default constructor for BinTree class
// Initializes an empty tree with root = NULL
BinTree::BinTree() {
   root = NULL;
}

// ---------------------------------------------------------------------------
// Destructor
// Destructor for BinTree class
// Clears all memory in the BinTree object by calling makeEmpty
BinTree::~BinTree() {
   makeEmpty();
}

// ---------------------------------------------------------------------------
// isEmpty
// Checks to see if the root of the BinTree is NULL, returns true if so
bool BinTree::isEmpty() const {
   return root == NULL;
}

// ---------------------------------------------------------------------------
// makeEmpty
// Clears all memory in the BinTree by calling makeEmptyHelper
void BinTree::makeEmpty() {
   if (!isEmpty()) { // tree is not already empty
      makeEmptyHelper(root);
      root = NULL;
   }
}

// ---------------------------------------------------------------------------
// makeEmptyHelper
// Takes in a root pointer and deletes all nodes pointed to by that root
// as well as any data contained by those nodes
void BinTree::makeEmptyHelper(Node*& rootPtr) {
   if (rootPtr != NULL) {
      makeEmptyHelper(rootPtr->left); // recursively delete left
      makeEmptyHelper(rootPtr->right); // recursively delete right
      
      delete rootPtr->data; // clear DataNode memory
      rootPtr->data = NULL;
      
      delete rootPtr; // clear Node memory
      rootPtr = NULL;
   }
}

// ---------------------------------------------------------------------------
// operator==
// Overloaded equality operator for BinTree class
// Returns whether or not two BinTree objects are the same
bool BinTree::operator==(const BinTree& other) const {
   return equalityHelper(root, other.root);
}

// ---------------------------------------------------------------------------
// operator!=
// Overloaded inequality operator for BinTree class
// Returns whether or not two BinTree objects are different
bool BinTree::operator!=(const BinTree& other) const {
   return !(*this == other);
}

// ---------------------------------------------------------------------------
// equalityHelper
// Traverses two BinTrees recursively and returns false if the trees are
// different, true otherwise
bool BinTree::equalityHelper(const Node* thisRoot,
                             const Node* otherRoot) const {
   
   if (thisRoot != NULL && otherRoot != NULL) { // neither node is empty
      if (*thisRoot->data == *otherRoot->data) { // the two nodes are same
         // check to see if the left and right are the same
         return equalityHelper(thisRoot->right, otherRoot->right) &&
         equalityHelper(thisRoot->left, otherRoot->left);
      } else { // the two nodes arent the same
         return false;
      }
   }
   // true if both nodes are empty, false otherwise
   return thisRoot == NULL && otherRoot == NULL;
}

// ---------------------------------------------------------------------------
// insert
// Inserts a Movie* object into the BinTree
bool BinTree::insert(Movie* value) {
   Node* temp = new Node; // make a new node with value
   temp->data = value;
   temp->left = NULL;
   temp->right = NULL;
   
   if (root == NULL) { // the tree is already empty
      root = temp; // add the node
      return true;
   } else { // check the rest of the tree for a spot
      bool inserted = insertHelper(root, temp);
      if (!inserted) { // the node already exists
         delete temp;  // clear memory
      }
      return inserted;
   }
}

// ---------------------------------------------------------------------------
// insertHelper
// Helps insert a Movie* object into the BinTree
bool BinTree::insertHelper(Node* rootPtr, Node* temp) {
   if (*temp->data == *rootPtr->data) { // node already exists
      return false;
   } else if (*temp->data < *rootPtr->data) { // go left
      if (rootPtr->left == NULL) { // spot is found
         rootPtr->left = temp;     // assign the new node to this spot
         return true;
      } else {
         return insertHelper(rootPtr->left, temp); // continue left
      }
   } else {                               // go right
      if (rootPtr->right == NULL) { // spot is found
         rootPtr->right = temp;     // assign
         return true;
      } else {
         return insertHelper(rootPtr->right, temp); // continue left
      }
   }
}


bool BinTree::treeBorrow(Movie* product) {
	if (root == NULL) { // tree is empty
       return false;    // nothing to retrieve
    } else {            // not empty
       return true;
    }

}

// ---------------------------------------------------------------------------
// retrieve
// Retrieves the pointer of a Movie object if it exists in the BinTree
// returns true if found, false otherwise
bool BinTree::retrieve(const Movie& value, Movie*& pointer) const {
   if (root == NULL) { // tree is empty
      return false;    // nothing to retrieve
   } else {            // not empty
      return retrieveHelper(root, value, pointer); // traverse tree
   }
}

// ---------------------------------------------------------------------------
// retrieveHelper
// Traverses the tree to find the passed in Movie object, returns true if
// found, false otherwise
bool BinTree::retrieveHelper(Node* rootPtr, const Movie& value,
                             Movie*& pointer) const {
   
   if (value == *rootPtr->data) { // object is found
      pointer = rootPtr->data;    // set it to pointer for access
      return true;
   } else if (value < *rootPtr->data) { // check left
      if (rootPtr->left != NULL) {
         return retrieveHelper(rootPtr->left, value, pointer);
      } else { // nothing left
         return false;
      }
   } else {                          // check right
      if (rootPtr->right != NULL) {
         return retrieveHelper(rootPtr->right, value, pointer);
      } else { // nothing right
         return false;
      }
   }
}

// ---------------------------------------------------------------------------
// getDepth
// Returns the depth of the passed in Movie object, returns 0 if that
// object is not in the tree
int BinTree::getDepth(const Movie& value) const {
   return getDepthHelper(value, root);
}

// ---------------------------------------------------------------------------
// getDepthHelper
// Traverses the tree recursively until the passed in object is found or all
// nodes have been visited and returns the depth of that object
int BinTree::getDepthHelper(const Movie& value, Node* rootPtr) const {
   if (rootPtr == NULL) { // dead end, object wasn't found
      return 0;
   } else if (*rootPtr->data == value) { // found it
      return 1;
   } else {
      int leftDepth = getDepthHelper(value, rootPtr->left);
      int rightDepth = getDepthHelper(value, rootPtr->right);
      if (leftDepth == 0 && rightDepth == 0) { // both dead ends
         return 0; // not found
      } else {
         // return the sum of all the levels visited
         return 1 + (leftDepth > rightDepth ? leftDepth : rightDepth);
      }
   }
}

// ---------------------------------------------------------------------------
// bstreeToArray
// Converts a BinTree object to an array, leaving the BinTree empty after
void BinTree::bstreeToArray(Movie* array[]) {
   if (root != NULL) {
      int index = 0; // starting index for array traversal
      bstreeToArrayHelper(array, root, index);
      makeEmpty();   // leave the tree empty afterwards
   }
}

// ---------------------------------------------------------------------------
// bstreeToArrayHelper
// Performs an inorder traversal of the BinTree object, adding its contents
// to an array
void BinTree::bstreeToArrayHelper(Movie* array[], Node* rootPtr,
                                  int& index) const {
   
   if (rootPtr->left != NULL) {
      bstreeToArrayHelper(array, rootPtr->left, index); // traverse left
   }
   
   array[index] = rootPtr->data; // add data to array
   index++;                      // increase index
   rootPtr->data = NULL;
   
   if (rootPtr->right != NULL) {
      bstreeToArrayHelper(array, rootPtr->right, index); // traverse right
   }
}

// ---------------------------------------------------------------------------
// arrayToBSTree
// Converts a sorted array to a balanced BinTree object
// Pre: the array must be sorted and have no more than 100 elements
void BinTree::arrayToBSTree(Movie* array[]) {
   int size = 0;
   for(;;) { // find how many non-NULL elements are in the array
      if (array[size] == NULL) {
         break;
      }
      size++;
   }
   arrayToBSTreeHelper(array, 0, size - 1); // build tree
}

// ---------------------------------------------------------------------------
// arrayToBSTreeHelper
// Constructs a balanced BinTree from a sorted array
void BinTree::arrayToBSTreeHelper(Movie* array[], int low, int high) {
   if (low <= high) { // valid index
      int rootIndex = (low + high) / 2; // find center of sub array
      
      insert(array[rootIndex]); // add it to tree
      array[rootIndex] = NULL;  // remove it from array
      
      arrayToBSTreeHelper(array, rootIndex + 1, high); // go left
      arrayToBSTreeHelper(array, low, rootIndex - 1);  // go right
   }
}

// ---------------------------------------------------------------------------
// operator<<
// Overloaded output operator for BinTree class
// Calls inorderHelper to print the contents of the BinTree inorder
ostream& operator<<(ostream& output, const BinTree& tree) {
   if (!tree.isEmpty()) { // there is something to print
      tree.inorderHelper(output, tree.root); // print it
   }
   return output;
}

// ---------------------------------------------------------------------------
// inorderHelper
// Outputs the contents of the BinTree object using an inorder traversal
void BinTree::inorderHelper(ostream& output, Node* rootPtr) const {
   if (rootPtr->left != NULL) {
      inorderHelper(output, rootPtr->left); // traverse left
   }
   output << *rootPtr->data << endl; // print data
   if (rootPtr->right != NULL) {
      inorderHelper(output, rootPtr->right); // traverse right
   }
}

#endif
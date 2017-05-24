/*
* Title: BST.cpp
* Abstract: Added function to BST class that finds
* the first common ancestor of two nodes in a BST
* Author: William Gillihan
* ID: CST370 Final Project 2
* Date: 02/24/2017
*/
/*-------------------Algorithm------------------------------------------------
While traversing tree from top to bottom,
	If node n we encounter with value between item1 and item2, i.e., 
	item1 < n < item2 or same as one of the item1 or item2,
		It is FCA of item1 and item2 (assuming that item1 < item2).
	Else continue to traverse the BST,
		If node’s value is greater than both item1 and item2
			Then our FCA lies in left side of the node,
		If it’s is smaller than both item1 and item2,
			Then FCA lies on right side.
	Otherwise root is FCA (assuming that both item1 and item2 are present in BST)

Time complexity is O(h) where h is the height of the tree in 
which is the furthest distance the tree will be traversed.
-----------------------------------------------------------------------------*/
#include <iostream>
#include <iomanip>

using namespace std;

#include "BST.h"

//--- Definition of constructor
BST::BST()
	: myRoot(0)
{}

bool BST::empty() const
{
	return myRoot == 0;
}


bool BST::search(const int & item) const
{
	BinNode * locptr = myRoot;
	bool found = false;
	while (!found && locptr != 0)
	{
		if (item < locptr->data)       // descend left
			locptr = locptr->left;
		else if (locptr->data < item)  // descend right
			locptr = locptr->right;
		else                           // item found
			found = true;
	}
	return found;
}


void BST::insert(const int & item)
{
	BinNode * locptr = myRoot;   // search pointer
	BinNode * parent = 0;        // pointer to parent of current node
	bool found = false;     // indicates if item already in BST
	while (!found && locptr != 0)
	{
		parent = locptr;
		if (item < locptr->data)       // descend left
			locptr = locptr->left;
		else if (locptr->data < item)  // descend right
			locptr = locptr->right;
		else                           // item found
			found = true;
	}
	if (!found)
	{                                 // construct node containing item
		locptr = new BinNode(item);
		if (parent == 0)               // empty tree
			myRoot = locptr;
		else if (item < parent->data)  // insert to left of parent
			parent->left = locptr;
		else                           // insert to right of parent
			parent->right = locptr;
	}
	else
		cout << "Item already in the tree\n";
}

/* Function to find First Common Ancestor of two nodes.
The function assumes that both nodes are present in BST */
int BST::fca(int item1, int item2)
{
	BinNode * root = myRoot;
	int myFCA;
	while (myRoot != 0)
	{
		/* If both item1 and item2 are smaller than root, 
			then FCA lies in left tree */
		if (myRoot->data > item1 && myRoot->data > item2)
			myRoot = myRoot->left;
		/* If both item1 and item2 are greater than root, 
			then FCA lies in right tree */
		else if (myRoot->data < item1 && myRoot->data < item2)
			myRoot = myRoot->right;
		else break;
	}
	myFCA = myRoot->data;
	myRoot = root; // reset to original root
	return myFCA;
}

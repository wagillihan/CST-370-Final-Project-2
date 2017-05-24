/*
* Title: BST.cpp
* Abstract: Added function declaration to interface that finds
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
using namespace std;

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

class BST
{
public:
	/***** Function Members *****/
	BST();
	bool empty() const;
	bool search(const int & item) const;
	void insert(const int & item);
	int fca(int item1, int item2); // Find First Common Ancestor

private:
	/***** Node class *****/
	class BinNode
	{
	public:
		int data;
		BinNode * left;
		BinNode * right;

		// BinNode constructors
		// Default -- data part is default int value; both links are null.
		BinNode()
			: left(0), right(0)
		{}

		// Explicit Value -- data part contains item; both links are null.
		BinNode(int item)
			: data(item), left(0), right(0)
		{}

	};// end of class BinNode declaration

	  /***** Data Members *****/
	BinNode * myRoot;

}; // end of class declaration

#endif

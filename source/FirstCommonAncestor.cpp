/*
* Title: FirstCommonAncestor.cpp
* Abstract: Driver program to test function that finds
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
#include "BST.h"


// driver function to test first common ancestor function
int main()
{
	/* build test BST
					80
				30		90
			20		60		100
		10		50		70
			40
	*/
	BST intBST;          
	intBST.insert(80);
	intBST.insert(30);
	intBST.insert(90);
	intBST.insert(20);
	intBST.insert(60);
	intBST.insert(100);
	intBST.insert(10);
	intBST.insert(50);
	intBST.insert(70);
	intBST.insert(40);

	cout << "First Common Ancestor of 30 and 100 is " <<
		intBST.fca(30, 100) << endl;
	cout << "First Common Ancestor of 40 and 60 is " <<
		intBST.fca(40, 60) << endl;
	cout << "First Common Ancestor of 20 and 60 is " <<
		intBST.fca(20, 60) << endl;
	cout << "First Common Ancestor of 30 and 60 is " <<
		intBST.fca(30, 60) << endl;
	cout << "First Common Ancestor of 20 and 50 is " <<
		intBST.fca(20, 50) << endl;
	cout << "First Common Ancestor of 20 and 40 is " <<
		intBST.fca(20, 40) << endl;
	bool loop = true;
	while (loop)
	{
		int item1, item2;
		cout << "Enter two numbers to find their FCA (-999 to stop)" << endl;
		cout << "First Number: ";
		cin >> item1;
		if (item1 == -999)
		{
			loop = false;
			break;
		}
		cout << "Second Number: ";
		cin >> item2;
		if (item2 == -999)
		{
			loop = false;
			break;
		}
      // make sure user enters two good values that are also in BST
		if (intBST.search(item1) & intBST.search(item2) && item1 != item2)
		{
			cout << "First Common Ancestor of " << item1 << " and " << 
				item2 << " is " << intBST.fca(item1, item2) << endl;
		}
		else
		{
			cout << "One or more of the numbers you ";
			cout << "have entered are not in the BST" << endl;
		}
	}
	system("pause");
	exit(0);
}
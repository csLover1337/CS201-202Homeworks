/**
* Title : Binary Search Trees
* Author : Omer Fatih Celik
* ID: 21601387
* Section : 1
* Assignment : 2
* Description : main file
*/

#include "analysis.h"
#include "PbTreeNode.h"
#include "PbBST.h"
#include <iostream>

using namespace std;

int main() {
	PbBST tree = PbBST();

	tree.insert(40);
	tree.insert(50);
	tree.insert(45);
	tree.insert(60);
	tree.insert(55);
	tree.insert(20);
	tree.insert(35);
	tree.insert(10);
	tree.insert(25);
	cout << "The tree height is " << tree.getHeight() << endl;
	tree.deleteKey(45);
	tree.deleteKey(50);
	cout << "The median of the (adjusted) tree is " << tree.medianOfBST() << endl;
	tree.rangeSearch(15, 53);
	cout << endl;
	analysis::heightAnalysis();
	return 0;
}
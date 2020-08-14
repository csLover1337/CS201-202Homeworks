/**
* Title : Binary Search Trees
* Author : Omer Fatih Celik
* ID: 21601387
* Section : 1
* Assignment : 2
* Description : header file of binary search tree
*/
#include "PbTreeNode.h"

class PbBST
{
public:
	PbBST();
	~PbBST();
	void insert(int key); 
	void deleteKey(int key);
	int getHeight();
	double medianOfBST();
	void rangeSearch(int a, int b);

	void rangeSearchTree(PbTreeNode * nodePtr, int a, int b);


	void insertItem(PbTreeNode*& nodePtr, int key);
	PbTreeNode* deleteItem(PbTreeNode* nodePtr, int key);
	PbTreeNode* deleteNodeItem(PbTreeNode* nodePtr);
	int getHeightOfNode(PbTreeNode* nodePtr);
	void deleteTree(PbTreeNode*& nodePtr);
	int getTreeSize(PbTreeNode* nodePtr);
	int getIndexAtInorder(int& index, PbTreeNode* nodePtr);
	PbTreeNode* root;
};


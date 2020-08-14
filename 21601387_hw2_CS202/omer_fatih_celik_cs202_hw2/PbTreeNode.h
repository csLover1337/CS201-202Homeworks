/**
* Title : Binary Search Trees
* Author : Omer Fatih Celik
* ID: 21601387
* Section : 1
* Assignment : 2
* Description : header file of tree node
*/
#ifndef PBTREENODE_HEADER
#define PBTREENODE_HEADER

class PbTreeNode {
public:
	PbTreeNode();
	~PbTreeNode();
	int item;
	PbTreeNode* left;
	PbTreeNode* right;
};
#endif // !PBTREENODE_HEADER


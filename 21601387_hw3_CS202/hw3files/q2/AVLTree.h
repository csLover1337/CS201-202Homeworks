/*
* Title : Heaps and AVL Trees
* Author : Ömer Fatih Çelik
* ID : 21601387
* Section : 1
* Assignment : 3
* Description : header file of the AVL tree without deletion
*/

#pragma once
#include "TreeNode.h"
class AVLTree
{
public:
	AVLTree();
	~AVLTree();
	void insert(int value);
	TreeNode* insertItem(TreeNode* nodePtr, int key);
	int getHeight();
	int getHeightOfNode(TreeNode* nodePtr);
	int getNumberOfRotations();
	void deleteTree(TreeNode*& nodePtr);
	void resetTree();
private:
	TreeNode* rotateLeft(TreeNode* nodePtr);
	TreeNode* rotateRight(TreeNode* nodePtr);
	void updateHeight(TreeNode* nodePtr);
	TreeNode* root;
	int rotations;
};


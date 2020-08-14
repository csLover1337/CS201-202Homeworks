/*
* Title : Heaps and AVL Trees
* Author : Ömer Fatih Çelik
* ID : 21601387
* Section : 1
* Assignment : 3
* Description : header file of AVL tree node
*/

#pragma once
class TreeNode
{
public:
	TreeNode();
	~TreeNode();
	TreeNode* left;
	TreeNode* right;
	int item;
	int height;
};


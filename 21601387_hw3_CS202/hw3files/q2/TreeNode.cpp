/*
* Title : Heaps and AVL Trees
* Author : Ömer Fatih Çelik
* ID : 21601387
* Section : 1
* Assignment : 3
* Description : source file of AVL tree node
*/

#include "TreeNode.h"
#include <iostream>


TreeNode::TreeNode() {
	left = NULL;
	right = NULL;
	height = 1;
}


TreeNode::~TreeNode() {
	left = NULL;
	right = NULL;
}

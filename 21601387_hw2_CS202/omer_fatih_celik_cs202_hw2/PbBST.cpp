/**
* Title : Binary Search Trees
* Author : Omer Fatih Celik
* ID: 21601387
* Section : 1
* Assignment : 2
* Description : source file of binary search tree
*/

#include "PbBST.h"
#include <iostream>
using namespace std;


PbBST::PbBST() {
	root = NULL;
}

PbBST::~PbBST() {
	deleteTree(root);
}

void PbBST::insert(int key) {
	insertItem(root, key);
}

void PbBST::insertItem(PbTreeNode*& nodePtr, int key) {
	if (nodePtr == NULL) {
		nodePtr = new PbTreeNode();
		nodePtr->item = key;
	}
	else {
		if (nodePtr->item >= key) {
			insertItem(nodePtr->left, key);
		}
		else {
			insertItem(nodePtr->right, key);
		}
	}
}

void PbBST::deleteKey(int key) {
	root = deleteItem(root, key);
}

PbTreeNode* PbBST::deleteItem(PbTreeNode* nodePtr, int key) {
	if (nodePtr == NULL) {
		return NULL;
	}
	else {
		if (key == nodePtr->item) {
			nodePtr = deleteNodeItem(nodePtr);
			return nodePtr;
		}
		else if (key < nodePtr->item) {
			nodePtr->left = deleteItem(nodePtr->left, key);
			return nodePtr;
		}
		else {
			nodePtr->right = deleteItem(nodePtr->right, key);
			return nodePtr;
		}
	}
}

PbTreeNode* PbBST::deleteNodeItem(PbTreeNode* nodePtr) {
	PbTreeNode* toDelete;

	if (nodePtr->left == NULL && nodePtr->right == NULL) {
		delete nodePtr;
		nodePtr = NULL;
		return NULL;
	}
	else if (nodePtr->left == NULL) {
		toDelete = nodePtr;
		nodePtr = nodePtr->right;
		toDelete->right = NULL;
		delete toDelete;
		return nodePtr;
	}
	else if (nodePtr->right == NULL) {
		toDelete = nodePtr;
		nodePtr = nodePtr->left;
		toDelete->left = NULL;
		delete toDelete;
		return nodePtr;
	}
	else {
		PbTreeNode* leftmostOfRightChild = nodePtr->right;
		PbTreeNode* predecessor = nodePtr;
		while (leftmostOfRightChild->left != NULL) {
			predecessor = leftmostOfRightChild;
			leftmostOfRightChild = leftmostOfRightChild->left;
		}
		nodePtr->item = leftmostOfRightChild->item;
		toDelete = leftmostOfRightChild;
		if (predecessor != nodePtr) {
			predecessor->left = leftmostOfRightChild->right;
		}
		else {
			predecessor->right = leftmostOfRightChild->right;
		}
		toDelete->right = NULL;
		delete toDelete;
		return nodePtr;
	}
}

int PbBST::getHeight() {
	return getHeightOfNode(root);
}

int PbBST::getHeightOfNode(PbTreeNode* nodePtr) {
	if (nodePtr == NULL) {
		return 0;
	}
	else if (nodePtr->left == NULL && nodePtr->right == NULL) {
		return 1;
	}
	else if (nodePtr->left == NULL) {
		return 1 + getHeightOfNode(nodePtr->right);
	}
	else if (nodePtr->right == NULL) {
		return 1 + getHeightOfNode(nodePtr->left);
	}
	else {
		int leftHeight = getHeightOfNode(nodePtr->left);
		int rightHeight = getHeightOfNode(nodePtr->right);
		if (leftHeight > rightHeight) {
			return 1 + leftHeight;
		}
		else {
			return 1 + rightHeight;
		}
	}
}

void PbBST::deleteTree(PbTreeNode*& nodePtr) {
	if (nodePtr != NULL) {
		deleteTree(nodePtr->left);
		deleteTree(nodePtr->right);
		delete nodePtr;
	}
}

double PbBST::medianOfBST() {
	int size = getTreeSize(root);
	int halfSize = size / 2;
	if (size % 2 == 1) {
		return getIndexAtInorder(halfSize, root);
	}
	else {
		int halfSizePlus = (size / 2) + 1;
		return (getIndexAtInorder(halfSize, root) + getIndexAtInorder(halfSizePlus, root)) / 2;
	}
}

int PbBST::getTreeSize(PbTreeNode* nodePtr) {
	if (nodePtr == NULL || nodePtr == 0) {
		return 0;
	}
	else {
		return (getTreeSize(nodePtr->left) + getTreeSize(nodePtr->right) + 1);
	}
}

int PbBST::getIndexAtInorder(int& index, PbTreeNode* nodePtr) {
	if (nodePtr == NULL || index < 1 ) {
		return -1;
	}
	getIndexAtInorder(index, nodePtr->left);
	if (index == 1) {
		return nodePtr->item;
	}
	index = index - 1;
	getIndexAtInorder(index, nodePtr->right);
}

void PbBST::rangeSearch(int a, int b) {
	cout << "[ ";
	rangeSearchTree(root, a, b);
	cout << "]" << endl;
}

void PbBST::rangeSearchTree(PbTreeNode* nodePtr, int a, int b) {
	if (nodePtr != NULL) {
		if (nodePtr->item > a) {
			rangeSearchTree(nodePtr->left, a, b);
		}
		if (nodePtr->item > a && nodePtr->item < b) {
			cout << nodePtr->item << " ";
		}
		if (nodePtr->item < b) {
			rangeSearchTree(nodePtr->right, a, b);
		}
	}
}
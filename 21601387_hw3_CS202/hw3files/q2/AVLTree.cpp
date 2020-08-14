/*
* Title : Heaps and AVL Trees
* Author : Ömer Fatih Çelik
* ID : 21601387
* Section : 1
* Assignment : 3
* Description : source file of AVL tree without deletion
*/

#include "AVLTree.h"
#include "TreeNode.h"
#include <iostream>

AVLTree::AVLTree() {
	root = NULL;
	rotations = 0;
}

AVLTree::~AVLTree() {
	deleteTree(root);
}

void AVLTree::deleteTree(TreeNode*& nodePtr) {
	if (nodePtr != NULL) {
		deleteTree(nodePtr->left);
		deleteTree(nodePtr->right);
		delete nodePtr;
	}
}

void AVLTree::resetTree() {
	deleteTree(root);
	rotations = 0;
	root = NULL;
}

int AVLTree::getNumberOfRotations() {
	return rotations;
}

void AVLTree::insert(int value) {
	root = insertItem(root, value);
}

TreeNode* AVLTree::insertItem(TreeNode* nodePtr, int value) {
	if (nodePtr == NULL) {
		TreeNode* newNode = new TreeNode();
		newNode->item = value;
		return newNode;
	}

	if (nodePtr->item > value) {
		nodePtr->left = insertItem(nodePtr->left, value);
	}
	else if (nodePtr->item < value) {
		nodePtr->right = insertItem(nodePtr->right, value);
	}
	else {
		return nodePtr;
	}

	updateHeight(nodePtr);
	
	int leftHeight = getHeightOfNode(nodePtr->left);
	int rightHeight = getHeightOfNode(nodePtr->right);
	if (leftHeight - rightHeight > 1 || leftHeight - rightHeight < 1) {
		if (leftHeight - rightHeight > 1 && value < nodePtr->left->item) {
			return rotateRight(nodePtr);
		}
		if (leftHeight - rightHeight > 1 && value > nodePtr->left->item) {
			nodePtr->left = rotateLeft(nodePtr->left);
			return rotateRight(nodePtr);
		}
		if (rightHeight - leftHeight > 1 && value > nodePtr->right->item) {
			return rotateLeft(nodePtr);
		}
		if (rightHeight - leftHeight > 1 && value < nodePtr->right->item) {
			nodePtr->right = rotateRight(nodePtr->right);
			return rotateLeft(nodePtr);
		}
	}
	return nodePtr;
}

TreeNode* AVLTree::rotateRight(TreeNode* nodePtr) {
	TreeNode* leftNode = nodePtr->left;
	TreeNode* rightOfLeft = leftNode->right;
	leftNode->right = nodePtr;
	nodePtr->left = rightOfLeft;
	rotations++;
	updateHeight(nodePtr);
	updateHeight(leftNode);
	return leftNode;
}

TreeNode* AVLTree::rotateLeft(TreeNode* nodePtr) {
	TreeNode* rightNode = nodePtr->right;
	TreeNode* leftOfRight = rightNode->left;
	rightNode->left = nodePtr;
	nodePtr->right = leftOfRight;
	rotations++;
	updateHeight(nodePtr);
	updateHeight(rightNode);
	return rightNode;
}

void AVLTree::updateHeight(TreeNode* nodePtr) {
	if (nodePtr != NULL) {
		if (nodePtr->left == NULL && nodePtr->right == NULL) {
			nodePtr->height = 1;
		}
		else if (nodePtr->right == NULL) {
			nodePtr->height = 1 + nodePtr->left->height;
		}
		else if (nodePtr->left == NULL) {
			nodePtr->height = 1 + nodePtr->right->height;
		}
		else if (nodePtr->left->height > nodePtr->right->height) {
			nodePtr->height = 1 + nodePtr->left->height;
		}
		else {
			nodePtr->height = 1 + nodePtr->right->height;
		}
	}
}

int AVLTree::getHeight() {
	return getHeightOfNode(root);
}

int AVLTree::getHeightOfNode(TreeNode* nodePtr) {
	if (nodePtr != NULL) {
		return nodePtr->height;
	}
	return 0;
}
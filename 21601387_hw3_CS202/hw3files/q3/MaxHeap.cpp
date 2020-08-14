/*
* Title : Heaps and AVL Trees
* Author : Ömer Fatih Çelik
* ID : 21601387
* Section : 1
* Assignment : 3
* Description : MaxHeap class source file
*/

#include "MaxHeap.h"
using namespace std;

MaxHeap::MaxHeap(int cap) {
	capacity = cap;
	size = 0;
	heapArray = new int[cap];
}

MaxHeap::~MaxHeap() {
	delete heapArray;
}

int MaxHeap::lastParentIndex() {
	return (size / 2) - 1;
}

int MaxHeap::firstLeafIndex() {
	return size / 2;
}

int MaxHeap::leftIndex(int i) {
	return 2 * i + 1;
}

int MaxHeap::rightIndex(int i) {
	return 2 * i + 2;
}

int MaxHeap::parentIndex(int i) {
	return (i - 1) / 2;
}

int MaxHeap::getLeafAmount() {
	return (size + 1) / 2;
}

int MaxHeap::getSize() {
	return size;
}

void MaxHeap::swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void MaxHeap::insert(int item) {
	if (size >= capacity) {
		return;
	}
	heapArray[size] = item;
	int i = 0;
	heapFix(size, i);
	size++;
}

// This function checks the called index element and it's parent
// If the parent is smaller then swaps and calls itself for the parent
void MaxHeap::heapFix(int i, int &swapCount) {
	int parent = parentIndex(i);
	if (i > 0 && heapArray[i] > heapArray[parent]) {
		swap(&heapArray[i], &heapArray[parent]);
		swapCount++;
		heapFix(parent, swapCount);
	}
}


//calls heapFix function for all of the leafs
void MaxHeap::heapFixAll(int& swapCount) {
	for (int i = firstLeafIndex(); i < size; i++) {
		heapFix(i, swapCount);
	}
}

void MaxHeap::permutation(int left, int right, int& swapCount, int& permutationCount) {
	int i;
	if (left == right) {
		// this part is an unique permutation
		// A temp array is created to save the array before fixing, after the fix it's loaded back
		int* temp = new int[size];
		for (i = 0; i < size; i++)
			temp[i] = heapArray[i];

		permutationCount++;
		heapFixAll(swapCount);

		for (i = 0; i < size; i++)
			heapArray[i] = temp[i];
		delete[] temp;
	}
	else
	{
		// this part is recursively calling loops to find permutations
		for (i = left; i <= right; i++)  
		{
			swap(&heapArray[left], &heapArray[i]);
			permutation(left + 1, right, swapCount, permutationCount);
			swap(&heapArray[left], &heapArray[i]);
		}
	}
}

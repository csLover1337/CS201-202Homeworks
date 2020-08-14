/*
* Title : Heaps and AVL Trees
* Author : Ömer Fatih Çelik
* ID : 21601387
* Section : 1
* Assignment : 3
* Description : MaxHeap class header file
*/

#pragma once
class MaxHeap
{
public:
	MaxHeap(int capacity);
	~MaxHeap();
	int getSize();
	void insert(int item);
	void heapFix(int i, int& swapCount);
	void heapFixAll(int& swapCount);
	void permutation(int left, int right, int & swapCount, int & permutationCount);
private:
	void swap(int* a, int* b);
	int parentIndex(int i);
	int rightIndex(int i);
	int leftIndex(int i);
	int	lastParentIndex();
	int firstLeafIndex();
	int getLeafAmount();
	int* heapArray;
	int capacity;
	int size;
};


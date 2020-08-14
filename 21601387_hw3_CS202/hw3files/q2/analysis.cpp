/*
* Title : Heaps and AVL Trees
* Author : Ömer Fatih Çelik
* ID : 21601387
* Section : 1
* Assignment : 3
* Description : source file of analysis class
*/

#include "analysis.h"
#include "AVLTree.h"
#include "TreeNode.h"
#include <cstdlib>
#include <time.h>
#include <iostream>
using namespace std;

void analysis::rotationAnalysis() {
	const int MAX_VALUE = 1000000;
	int arraySize;
	int* array;
	AVLTree tree = AVLTree();
	int* results = new int[30];
	int resultsIndex = 0;

	// random insertions
	for (arraySize = 1000; arraySize <= 10000; arraySize = arraySize + 1000) {
		array = new int[arraySize];
		srand(time(NULL));
		for (int i = 0; i < arraySize; i++) {
			array[i] = rand() % MAX_VALUE;
			array[i]++;
			tree.insert(array[i]);
		}
		delete[] array;
		results[resultsIndex] = tree.getNumberOfRotations();
		resultsIndex++;
		tree.resetTree();
	}
	cout << endl;
	
	// increasing insertions
	for (arraySize = 1000; arraySize <= 10000; arraySize = arraySize + 1000) {
		array = new int[arraySize];
		for (int i = 0; i < arraySize; i++) {
			array[i] = (10 * i) + 9;
			tree.insert(array[i]);
		}
		delete[] array;
		results[resultsIndex] = tree.getNumberOfRotations();
		resultsIndex++;
		tree.resetTree();
	}
	cout << endl;
	
	// decreasing insertions
	for (arraySize = 1000; arraySize <= 10000; arraySize = arraySize + 1000) {
		array = new int[arraySize];
		for (int i = arraySize - 1; i >= 0; i--) {
			array[i] = (10 * i) + 9;
			tree.insert(array[i]);
		}
		delete[] array;
		results[resultsIndex] = tree.getNumberOfRotations();
		resultsIndex++;
		tree.resetTree();
	}

	cout << "Array Size       Random       Ascending        Descending        " << endl;
	cout << "1000             " << results[0] << "           " << results[10] << "              " << results[20] << endl;
	cout << "2000             " << results[1] << "          " << results[11] << "             " << results[21] << endl;
	cout << "3000             " << results[2] << "          " << results[12] << "             " << results[22] << endl;
	cout << "4000             " << results[3] << "          " << results[13] << "             " << results[23] << endl;
	cout << "5000             " << results[4] << "          " << results[14] << "             " << results[24] << endl;
	cout << "6000             " << results[5] << "          " << results[15] << "             " << results[25] << endl;
	cout << "7000             " << results[6] << "          " << results[16] << "             " << results[26] << endl;
	cout << "8000             " << results[7] << "          " << results[17] << "             " << results[27] << endl;
	cout << "9000             " << results[8] << "          " << results[18] << "             " << results[28] << endl;
	cout << "10000            " << results[9] << "          " << results[19] << "             " << results[29] << endl;
	delete[] results;
 }

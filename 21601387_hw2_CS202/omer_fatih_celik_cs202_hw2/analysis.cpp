/**
* Title : Binary Search Trees
* Author : Omer Fatih Celik
* ID: 21601387
* Section : 1
* Assignment : 2
* Description : source file of analysis
*/

#include <cstdlib>
#include <time.h>
#include "analysis.h"
#include "PbBST.h"
#include "PbTreeNode.h"
#include <iostream>
using namespace std;

void analysis::heightAnalysis() {
	const int ARRAY_SIZE = 20000;
	int randomArray[ARRAY_SIZE];

	PbBST tree = PbBST();

	srand(time(NULL));
	for (int i = 0; i < ARRAY_SIZE; i++) {
		randomArray[i] = rand() % 100000;
	}



	cout << "Part f - Analysis of BST height - part 1" << endl;
	cout << "----------------------------------------" << endl;
	cout << "Tree Size             Tree Height" << endl;
	cout << "----------------------------------------" << endl;
	for (int i = 1; i < ARRAY_SIZE + 1; i++) {
		tree.insert(randomArray[i - 1]);
		if (i % 1000 == 0) {
			cout << i << "                       " << tree.getHeight() << endl;
		}
	}
	cout << endl << endl;

	int randomArray2[ARRAY_SIZE];
	int indexList[ARRAY_SIZE];
	int inserted = 0;
	int randomNumber;

	for (int i = 0; i < ARRAY_SIZE; i++) {
		indexList[i] = 1;
	}
	srand(time(NULL));
	while (inserted != 20000) {
		randomNumber = rand() % 20000;
		if (indexList[randomNumber] == 1) {
			randomArray2[randomNumber] = randomArray[inserted];
			indexList[randomNumber] = 0;
			inserted++;
		}
	}
	for (int i = 0; i < ARRAY_SIZE; i++) {
		randomArray[i] = randomArray2[i];
	}

	cout << "Part f - Analysis of BST height - part 2" << endl;
	cout << "----------------------------------------" << endl;
	cout << "Tree Size             Tree Height" << endl;
	cout << "----------------------------------------" << endl;
	for (int i = ARRAY_SIZE; i > 0; i--) {
		tree.deleteKey(randomArray[i - 1]);
		if (i % 1000 == 0) {
			cout << i << "                       " << tree.getHeight() << endl;
		}
	}
}

